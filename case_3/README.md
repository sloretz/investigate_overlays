# Case 2

The underlay is extended by the overlay.
`pkg_a` exists in both the overlay and the underlay

```
catkin_make install
```

## Workspace Arrangement


### Workspace graph

What is desired here?


```

  ┌─────┐       ┌───────────────┐
  │pkg_a├───────►overlay_checker│
  └───┬─┘       └──────────▲────┘
      │                    │
      └──────────┐         │  Overlay
  ---------------│---------│----------
                 │         │  Underlay
  ┌─────┐        │      ┌──┴──┐
  │pkg_a│        └──────►pkg_b│
  └─────┘               └─────┘
```

But is the reality more like?
Depends build-time vs run time.

```
 ┌─────┐       ┌───────────────┐
 │pkg_a├───────►overlay_checker│
 └─────┘       └──────────▲────┘
                          │
                          │  Overlay
 -------------------------│----------
                          │  Underlay
 ┌─────┐               ┌──┴──┐
 │pkg_a├───────────────►pkg_b│
 └─────┘               └─────┘
```

### Underlay contents

* `pkg_a`
  * Depends on: None
* `pkg_b`
  * Depends on: `pkg_a`

## Overlay contents

* `pkg_a`
  * Depends on: None
* `overlay_checker`
  * Depends on `pkg_a` then `pkg_b`

