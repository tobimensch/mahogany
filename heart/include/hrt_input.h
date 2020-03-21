#ifndef HRT_INPUT_H
#define HRT_INPUT_H

#include <wayland-server.h>
#include <wlr/types/wlr_input_device.h>
#include <wlr/types/wlr_keyboard_group.h>

struct hrt_server;

struct hrt_seat {
  struct hrt_server *server;

  struct wlr_cursor *cursor;
  struct wlr_keyboard_group *keyboard_group;
  struct wlr_xcursor_manager *xcursor_manager;
  struct wlr_seat *seat;
  struct wl_list inputs;
  struct wl_listener new_input;

  // cursor events:
  struct wl_listener motion;
  struct wl_listener motion_absolute;
  struct wl_listener axis;
  struct wl_listener frame;

  // keyboard events:
  struct wl_listener keyboard_key;
  struct wl_listener keyboard_modifiers;
};

struct hrt_input {
  struct wlr_input_device *wlr_input_device;
  struct hrt_seat *seat;
  struct wl_list link;

  struct wl_listener destroy;
};

bool hrt_seat_init(struct hrt_seat *seat, struct hrt_server *server);
void hrt_cursor_init(struct hrt_seat *seat);
void hrt_keyboard_init(struct hrt_seat *seat);

#endif