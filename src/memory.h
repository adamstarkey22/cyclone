#ifndef _CYCLONE_MEMORY_H_
#define _CYCLONE_MEMORY_H_

#define GROW_ARRAY_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, old_capacity, new_capacity) \
    (type*)reallocate(pointer, sizeof(type) * (old_capacity), sizeof(type) * new_capacity)

#define FREE_ARRAY(type, pointer, capacity) \
    reallocate(pointer, sizeof(type) * (capacity), 0)

void *reallocate(void *pointer, int old_size, int new_size);

#endif