# Case 1

No packages are overlaid.
The overlay only adds a new package.

## Building and running this example

```
cd underlay
. /opt/ros/noetic/setup.bash
catkin_make install
. install/setup.bash
cd ../overlay
catkin_make install
. install/setup.bash
./install/lib/checker/check_overlay
```


## Workspace Arrangement


### Desired workspace graph
```
              ┌───────┐
  ┌───────────►checker│
  │           └────▲──┘
  │                │
  │                │   Overlay
--│----------------│-----------
  │                │   Underlay
┌─┴───┐          ┌─┴───┐
│pkg_a├──────────►pkg_b│
└─────┘          └─────┘
```

### Underlay contents

* `pkg_a`
  * Depends on: None
* `pkg_b`
  * Depends on: `pkg_a`

## Overlay contents

* `overlay_checker`
  * Depends on `pkg_a` then `pkg_b`
