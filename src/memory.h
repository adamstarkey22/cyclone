#ifndef _CYCLONE_MEMORY_H_
#define _CYCLONE_MEMORY_H_

#define C_GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define C_GROW_ARRAY(type, pointer, old_count, new_count) \
    (type*)reallocate(pointer, sizeof(type) * (old_count), sizeof(type) * new_count)

#define C_FREE_ARRAY(type, pointer, count) \
    reallocate(pointer, sizeof(type) * (count), 0)

void *reallocate(void *pointer, int old_size, int new_size);

#endif