#include "internal.h"
#include "memory.h"

void c_init_program_array(CProgramArray *array)
{
    array->capacity = 0;
    array->data = NULL;
}

void c_free_program_array(CProgramArray *array)
{
    for (int i = 0; i < array->capacity; ++i) {
        if (array->data[i] != 0) {
            c_free_program(&array->data[i]);
        }
    }

    FREE_ARRAY(CProgram, array->data, array->capacity);
    c_init_program_array(array);
}

int c_push_program(CProgramArray *array, CProgram program)
{
    int index = 0;
    while (index < array->capacity) {
        if (array->data[index] == 0) break;
        ++index;
    }

    if (index == array->capacity) {
        int old_capacity = array->capacity;
        array->capacity = GROW_ARRAY_CAPACITY(old_capacity);
        array->data = GROW_ARRAY(CProgram, array->data, old_capacity, array->capacity);

        for (int i = old_capacity; i < array->capacity; ++i) {
            c_zero_program(&array->data[i]);
        }
    }

    array->data[index] = program;
    return index;
}

void c_erase_program(CProgramArray *array, int index)
{
    c_free_program(&array->data[index]);
}