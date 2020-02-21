#include "LinearHash.h"

bool_t CreateHash(hash_t* hsp, int size);

int CalcHashValue(hash_t* hsp, int key);

bool_t InputHash(hash_t* hsp, int data);

int SearchHash(hash_t* hsp, int data);

bool_t DeleteHash(hash_t* hsp, int data);

void PrintHash(hash_t* hsp);

void DestroyHash(hash_t* hsp);