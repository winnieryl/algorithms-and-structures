/*
* @Author: root
* @Date:   2017-07-05 16:34:59
* @Last Modified by:   root
* @Last Modified time: 2017-07-05 17:28:37
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hashmap.h"
#include "mylib.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)


typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];
    int number;
} data_struct_t;



#ifdef HASHMAP
int main(int argc, char* argv)
{
    int index;
    int error;
    map_t mymap;
    char key_string[KEY_MAX_LENGTH];
    data_struct_t* value;

    mymap = hashmap_new();

    for(index=0; index<KEY_COUNT; index+=1)
    {
        value = malloc(sizeof(data_struct_t));
        snprintf(value->key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);
        value->number = index;

        error = hashmap_put(mymap, value->key_string, value);

        assert(error==MAP_OK);
    }

    for(index=0; index<KEY_COUNT; index+=1)
    {
        snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);

        error = hashmap_get(mymap, key_string, (void**)(&value));

        assert(error==MAP_OK);
        assert(value->number==index);
    }

    snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, KEY_COUNT);
    error = hashmap_get(mymap, key_string, (void**)(&value));
    assert(error==MAP_MISSING);

    for(index=0; index<KEY_COUNT; index+=1)
    {
        snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);
        error = hashmap_get(mymap, key_string, (void**)(&value));
        if(error != 0)
            printf("error:%d, index: %d", error, index);
        assert(error==MAP_OK);

        error = hashmap_remove(mymap, key_string);
        assert(error==MAP_OK);

        free(value);

        error = hashmap_get(mymap, key_string, (void**)(&value));
        assert(error==MAP_MISSING);

    }

    hashmap_free(mymap);

    return 0;
}

#endif