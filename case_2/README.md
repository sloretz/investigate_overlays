# Case 2

The underlay is extended by the overlay.
`pkg_b` exists in both the overlay and the underlay

```
catkin_make install
```

## Workspace Arrangement


### Desired workspace graph

```
┌─────┐       ┌───────────────┐
│pkg_b├───────►overlay_checker│
└─▲───┘       └──────▲────────┘
  │                  │
  │  ┌───────────────┘      Overlay
--│--│------------------------------
  │  │                      Underlay
┌─┴──┴┐               ┌─────┐
│pkg_a├───────────────►pkg_b│
└─────┘               └─────┘
```

### Underlay contents

* `pkg_a`
  * Depends on: None
* `pkg_b`
  * Depends on: `pkg_a`

## Overlay contents

* `pkg_b`
  * Depends on: `pkg_a`
* `overlay_checker`
  * Depends on `pkg_a` then `pkg_b`
