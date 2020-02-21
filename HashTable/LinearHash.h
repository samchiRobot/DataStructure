#pragma once

#define EMPTY	-1
#define DELETE	-2

typedef enum {FALSE, TRUE} bool_t;

typedef struct _node
{
	int key;
	struct _node* next;
}node_t;

typedef struct _linear_hash
{
	node_t* hash;
	int size;
	int cnt;
}hash_t;

bool_t CreateHash(hash_t* hsp, int size);

int CalcHashValue(hash_t* hsp, int key);

bool_t InputHash(hash_t* hsp, int data);

int SearchHash(hash_t* hsp, int data);

bool_t DeleteHash(hash_t* hsp, int data);

void PrintHash(hash_t* hsp);

void DestroyHash(hash_t* hsp);
