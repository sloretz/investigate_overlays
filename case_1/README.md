# Case 1

This is the base case.
The underlay is extended by the overlay.
No packages are overlaid.

```
catkin_make install
```


## Workspace Arrangement


### Desired workspace graph
```
              ┌───────────────┐
  ┌───────────►overlay_checker│
  │           └─────────▲─────┘
  │                     │
  │                     │   Overlay
--│---------------------│-----------
  │                     │   Underlay
┌─┴───┐               ┌─┴───┐
│pkg_a├───────────────►pkg_b│
└─────┘               └─────┘
```

### Underlay contents

* `pkg_a`
  * Depends on: None
* `pkg_b`
  * Depends on: `pkg_a`

## Overlay contents

* `overlay_checker`
  * Depends on `pkg_a` then `pkg_b`
