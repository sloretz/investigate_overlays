# Two Catkin Packages Overlay

This folder has examples for overlaying a catkin workspace when the underlay contains two catkin packages.
Both `pkg_a` and `pkg_b` are catkin packages.
In all cases `pkg_b` depends on `pkg_a`.
Package `pkg_b` depends on `pkg_a` is shown with an arrow from `pkg_a` to `pkg_b`.

```
 ┌─────┐       ┌─────┐
 │pkg_a├───────►pkg_b│
 └─────┘       └─────┘
```

## Case 1: Overlay only adds a new package

The overlay workspace adds a new catkin package `checker` that depends on `pkg_a` and `pkg_b`.

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

## Case 2: Overlay replaces a leaf package

The overlay workspace adds a new catkin package `checker`, and a different version of `pkg_b`.
`pkg_b` in the overlay has API and ABI changes from the version in the underlay.

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

## Case 3: Overlay replaces a non-leaf package

The overlay workspace adds a new catkin package `checker`, and a different version of `pkg_a`.
`pkg_a` in the overlay has API and ABI changes from the version in the underlay.

The desired graph after sourcing the built overlay looks like this:

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

However, `pkg_b` in the underlay still expects the API/ABI of the version of `pkg_a` in the underlay.

```
  ┌─────┐       ┌───────────────┐
  │pkg_a├───────►overlay_checker│
  └───┬─┘       └──────────▲────┘
      │                    │
      └──────────┐         │  Overlay
  ---------------│---------│----------
                 │         │  Underlay
  ┌─────┐        │      ┌──┴──┐
  │pkg_a│-------►└──────►pkg_b│
  └─────┘               └─────┘
```
