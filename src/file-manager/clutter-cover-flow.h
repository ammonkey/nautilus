/* clutter-cover-flow.h */

#ifndef _CLUTTER_COVER_FLOW
#define _CLUTTER_COVER_FLOW

#include <gtk/gtk.h>
#include <gio/gio.h>
#include <clutter/clutter.h>

G_BEGIN_DECLS

#define CLUTTER_TYPE_COVER_FLOW clutter_cover_flow_get_type()

#define CLUTTER_COVER_FLOW(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_COVER_FLOW, ClutterCoverFlow))

#define CLUTTER_COVER_FLOW_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_COVER_FLOW, ClutterCoverFlowClass))

#define CLUTTER_IS_COVER_FLOW(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_COVER_FLOW))

#define CLUTTER_IS_COVER_FLOW_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_COVER_FLOW))

#define CLUTTER_COVER_FLOW_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_COVER_FLOW, ClutterCoverFlowClass))

typedef struct _ClutterCoverFlowPrivate ClutterCoverFlowPrivate;

typedef struct {
  ClutterGroup parent;
  ClutterCoverFlowPrivate *priv;
} ClutterCoverFlow;

typedef struct {
  ClutterGroupClass parent_class;
} ClutterCoverFlowClass;

typedef void (*ClutterCoverFlowGetInfoCallback)(GFile *file, char **name, char **description, GdkPixbuf **pb, guint pbsize);

GType clutter_cover_flow_get_type (void);

ClutterCoverFlow* clutter_cover_flow_new (ClutterActor *stage);

void clutter_cover_flow_add_gfile(ClutterCoverFlow *coverflow, GFile *file);

void clutter_cover_flow_add_gfile_with_info_callback(ClutterCoverFlow *coverflow, GFile *file, ClutterCoverFlowGetInfoCallback cb);

void clutter_cover_flow_left(ClutterCoverFlow *coverflow);

void clutter_cover_flow_right(ClutterCoverFlow *coverflow);

void clutter_cover_flow_scroll_to_actor(ClutterCoverFlow *coverflow, ClutterActor * actor);

G_END_DECLS

#endif /* _CLUTTER_COVER_FLOW */
