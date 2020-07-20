/**
 * \file this file contains definitions and declarations for managing sessions
 */

#include <picohttpparser.h>
#include <py/obj.h>

/**
 * session representation
 *
 * this struct represents a single HTTP session
 */
typedef struct session {
  char *rbuff;       /**< pointer to receive buffer */
  size_t rbuff_size; /**< size of receive buffer */
  char *sbuff;       /**< pointer to send buffer */
  size_t sbuff_size; /**< size of send buffer */
  void *data;        /**< some data related to this session */
} session;

/**
 * this struct holds all thing necessary for session manager
 */
typedef struct {
  size_t current_sessions;  /**< current number of sessions */
  size_t max_sessions;      /**< maximum number of sessions allowed */
  bipbuf_t sessions_buffer; /**< storage for sessions */
  char preallocated;        /**< whether buffer is preallocated */
  int (*session_factory)(struct session_manager *);
} session_manager;

/**
 * initialize a new session
 *
 * @param ses pointer to allocated session
 * @param rbuff_size initial size of receive buffer
 * @param sbuff_size initial size of send buffer
 *
 * @returns 0 on success, non zero otherwise
 */
int session_init(session *ses, size_t rbuff_size, size_t sbuff_size);

/**
 * free session, the session itself will not freed (to use it again)
 *
 * @param ses pointer to session
 */
void session_free(session *ses);

/**
 * initialize a new session manager. all settings will be adopted from
 * object itself.
 *
 * @param ses_man preallocated (the object itself) to initialize
 * @returns 0 on success, no-zero otherwise
 */
int session_manager_init(session_manager *ses_man);

/******************************************************************************
 * Micropython codes
 ******************************************************************************/
typedef struct _mp_obj_session_t {
  mp_obj_base_t base;
  session ses;
  mp_obj_t conn_context;
} mp_obj_session_t;

STATIC void session_print(const mp_print_t *print, mp_obj_t self_in,
                          mp_print_kind_t kind);

STATIC mp_obj_t session_get_rbuff(size_t nargs, mp_obj_t *args);
STATIC mp_obj_t session_get_rbuff_size(size_t nargsi, mp_obj_t *args);
typedef struct _mp_obj_session_manager_t {
  mp_obj_base_t base;
  session_manager manager;
} mp_obj_session_manager_t;
