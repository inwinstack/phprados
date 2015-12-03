#ifndef PHP_RADOS_H
#define PHP_RADOS_H

#define PHP_RADOS_EXTNAME  "rados"
#define PHP_RADOS_EXTVER   "0.9.3"

#include "php.h"
#include "php_ini.h"
#include "zend_exceptions.h"
#include "ext/standard/info.h"
#include "rados/librados.h"
#include <stdbool.h>
#ifdef ZTS
#include "TSRM.h"
#endif

#define PHP_RADOS_SNAP_NAME_MAX_LENGTH 64
#define PHP_RADOS_SNAP_MAX_NUM 256
#define PHP_RADOS_POOL_NAME_MAX_LENGTH 128
#define PHP_RADOS_OID_NAME_MAX_LENGTH 256
#define PHP_RADOS_CLUSTER_RES_NAME "RADOS Cluster"
#define PHP_RADOS_IOCTX_RES_NAME "RADOS IOCtx"
//aio
#define PHP_RADOS_COMPLETION_RES_NAME "RADOS Completion"

typedef struct _php_rados_cluster {
    rados_t cluster;
    bool connected;
} php_rados_cluster;

typedef struct _php_rados_ioctx {
    rados_ioctx_t io;
} php_rados_ioctx;

// aio
typedef struct _php_rados_completion {
    rados_completion_t comp;
  int count;
} php_rados_completion;
/// End

PHP_MINIT_FUNCTION(rados);
PHP_MSHUTDOWN_FUNCTION(rados);
PHP_MINFO_FUNCTION(rados);

PHP_FUNCTION(rados_create);
PHP_FUNCTION(rados_create2);
PHP_FUNCTION(rados_shutdown);
PHP_FUNCTION(rados_connect);
PHP_FUNCTION(rados_conf_read_file);
PHP_FUNCTION(rados_conf_set);
PHP_FUNCTION(rados_conf_get);
PHP_FUNCTION(rados_ioctx_create);
PHP_FUNCTION(rados_ioctx_destroy);
PHP_FUNCTION(rados_pool_list);
PHP_FUNCTION(rados_pool_lookup);
PHP_FUNCTION(rados_pool_create);
PHP_FUNCTION(rados_pool_delete);
PHP_FUNCTION(rados_ioctx_pool_set_auid);
PHP_FUNCTION(rados_ioctx_pool_get_auid);
PHP_FUNCTION(rados_write);
PHP_FUNCTION(rados_write_full);
PHP_FUNCTION(rados_read);
PHP_FUNCTION(rados_remove);
PHP_FUNCTION(rados_trunc);
PHP_FUNCTION(rados_append);
PHP_FUNCTION(rados_clone_range);
PHP_FUNCTION(rados_getxattr);
PHP_FUNCTION(rados_setxattr);
PHP_FUNCTION(rados_rmxattr);
PHP_FUNCTION(rados_stat);
PHP_FUNCTION(rados_get_last_version);
PHP_FUNCTION(rados_getxattrs);
PHP_FUNCTION(rados_objects_list);
PHP_FUNCTION(rados_ioctx_snap_create);
PHP_FUNCTION(rados_ioctx_snap_remove);
PHP_FUNCTION(rados_rollback);
PHP_FUNCTION(rados_ioctx_snap_list);
PHP_FUNCTION(rados_ioctx_snap_lookup);
PHP_FUNCTION(rados_ioctx_snap_get_name);
PHP_FUNCTION(rados_ioctx_snap_get_stamp);
PHP_FUNCTION(rados_cluster_stat);
PHP_FUNCTION(rados_ioctx_pool_stat);
PHP_FUNCTION(rados_cluster_fsid);
PHP_FUNCTION(rados_wait_for_latest_osdmap);
PHP_FUNCTION(rados_pool_reverse_lookup);
PHP_FUNCTION(rados_get_instance_id);
PHP_FUNCTION(rados_ioctx_create2);
PHP_FUNCTION(rados_ioctx_get_id);
PHP_FUNCTION(rados_ioctx_get_pool_name);
// aio
PHP_FUNCTION(rados_aio_create_completion);
PHP_FUNCTION(rados_aio_get_return_value);
PHP_FUNCTION(rados_aio_wait_for_complete);
PHP_FUNCTION(rados_aio_wait_for_safe);
PHP_FUNCTION(rados_aio_release);
PHP_FUNCTION(rados_aio_write_full);
PHP_FUNCTION(rados_aio_append);
/// End
extern zend_module_entry rados_module_entry;
#define phpext_rados_ptr &rados_module_entry;

#endif
