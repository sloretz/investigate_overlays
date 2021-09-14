# Leaf Package Overlay with Standard CMake Package Finding

This folder has examples for overlaying a leaf package in a workspace, where some packages in the overlay use standard CMake `find_package()` calls.

All packages are catkin packages.
`pkg_b` depends on `pkg_a`.

```
 ┌─────┐       ┌─────┐
 │pkg_a├───────►pkg_b│
 └─────┘       └─────┘
```

## Case 1: Checker depends on `pkg_a`, then `pkg_b`
The overlay workspace adds a new package `checker` and a different version of `pkg_b`.
`checker` adds the include directories for `pkg_a` before `pkg_b`.
This means the underlay workspace's include directories are searched before the overlay's include directories.
When `checker` builds, it will build against the underlay version of `pkg_b`, but at runtime it will use the rungime library of `pkg_b` in the overlay.

```
┌─────┐    ┌───────┐
│pkg_b├────►checker│
└─▲───┘    └──▲────┘
  │           │
  │  ┌────────┘   Overlay
--│--│--------▲-----------
  │  │        |   Underlay
┌─┴──┴┐       | ┌─────┐
│pkg_a│       └─│pkg_b│
└─────┘         └─────┘
```

## Case 2: Checker depends on `pkg_b`, then `pkg_a`
The overlay workspace adds a new package `checker` and a different version of `pkg_b`.
`checker` adds the include directories for `pkg_b` before `pkg_a`.
This means the overlay workspace's include directories are searched before the underlay's include directories.
Everything works fine in this case.

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
