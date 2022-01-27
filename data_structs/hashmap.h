#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#define MAP_MISSING -3 /* no such element */
#define MAP_FULL -2    /* hash map is full */
#define MAP_OMEM -1    /* out of memory */
#define MAP_OK 0       /* OK */


typedef void *any_t;

typedef int *(PFany)(any_t, any_t);

typedef any_t map_t;

extern map_t hashmap_new();

extern int hashmap_iterate(map_t in, PFany f, any_t item);

extern int hashmap_put(map_t in, char* key, any_t value);

extern int hashmap_get(map_t in, char* key, any_t *arg);

extern int hashmap_remove(map_t in, char* key);

extern void hashmap_free(map_t in);

extern int hashmap_length(map_t in);


#endif