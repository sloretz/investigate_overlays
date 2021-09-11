# Case 3

The underlay is extended by the overlay.
`pkg_a` exists in both the overlay and the underlay.
`pkg_b`'s binary artifacts remember information from `pkg_a` in the underlay, causing problems at runtime.

```
catkin_make install
```

## Workspace Arrangement


### Dependency Graph

Underlay-only graph
```
 ┌─────┐       ┌─────┐
 │pkg_a├───────►pkg_b│
 └─────┘       └─────┘
```

Desired graph after sourcing overlay
```
  ┌─────┐   ┌───────────────┐
  │pkg_a├───►overlay_checker│
  └───┬─┘   └──────────▲────┘
      │                │
      └──────┐         │  Overlay
  -----------│---------│----------
             │         │  Underlay
  ┌─────┐    │      ┌──┴──┐
  │pkg_a│    └──────►pkg_b│
  └─────┘           └─────┘
```

Reality: `pkg_b` binary artifacts expect API/ABI of `pkg_a` in underlay
```
  ┌─────┐       ┌───────────────┐
  │pkg_a├───────►overlay_checker│
  └───┬─┘       └──────────▲────┘
      │                    │
      └──────────┐         │  Overlay
  ---------------│---------│----------
                 │         │  Underlay
  ┌─────┐        │      ┌──┴──┐
  │pkg_a│------->└──────►pkg_b│
  └─────┘               └─────┘
```

### Underlay

* `pkg_a`
  * Depends on: None
* `pkg_b`
  * Depends on: `pkg_a`

## Overlay

* `pkg_a`
  * Depends on: None
* `overlay_checker`
  * Depends on `pkg_a` then `pkg_b`

