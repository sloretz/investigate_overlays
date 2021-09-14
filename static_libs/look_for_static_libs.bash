IFS=$'\n'
ros_pkgs=( $(apt list "ros-noetic-*" |awk -F'/' 'NR>1{print $1}') )


for pkg in ${ros_pkgs[@]} ; do
  apt-get download $pkg > /dev/null
  dpkg --contents *.deb | grep "\.a$"
  rm ros-noetic-*.deb
done
