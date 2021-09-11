# Case 2

The underlay is extended by the overlay.
`pkg_b` exists in both the overlay and the underlay

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


### Dependency Graph

Underlay-only graph
```
 ┌─────┐       ┌─────┐
 │pkg_a├───────►pkg_b│
 └─────┘       └─────┘
```

Graph after sourcing overlay
```
┌─────┐    ┌───────┐
│pkg_b├────►checker│
└─▲───┘    └──▲────┘
  │           │
  │  ┌────────┘   Overlay
--│--│--------------------
  │  │            Underlay
┌─┴──┴┐         ┌─────┐
│pkg_a│         │pkg_b│
└─────┘         └─────┘
```

### Underlay

* `pkg_a`
  * Depends on: None
* `pkg_b`
  * Depends on: `pkg_a`

## Overlay

* `pkg_b`
  * Depends on: `pkg_a`
* `overlay_checker`
  * Depends on `pkg_a` then `pkg_b`
