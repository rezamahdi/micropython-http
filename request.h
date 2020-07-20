#ifndef MP_REQUEST_H_
#define MP_REQUEST_H_

#include "picohttpparser.h"
#include <py/dynruntime.h>
#include <py/obj.h>

typedef struct {
  char method;                 /**< method of request */
  char *url;                   /**< url */
  size_t url_size;             /**< size of url */
  char version;                /**< version (minor) */
  struct phr_header headers[]; /**< headers */
} request_t;

int request_init(request_t *req, size_t num_headers);
int request_free(request_t *req);

/*******************************************************************************
 * micropython code
 ******************************************************************************/

typedef struct {
	mp_obj_base_t base;
	request_t request;
} mp_request_t;

#endif
