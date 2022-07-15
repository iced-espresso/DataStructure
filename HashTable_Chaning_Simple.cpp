#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <vcruntime_string.h>
#include <string.h>

const int MAX_TABLE = 5;

struct HashEntry
{
    const char* key;
    int data;
    HashEntry* nextChain;
};

HashEntry* tb[MAX_TABLE];

unsigned long hash(const char* str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
    {
        hash = (((hash << 5) + hash) + c) % MAX_TABLE;
    }

    return hash % MAX_TABLE;
}

int getLen(const char* key)
{
    int len = 0;
    while (*key++)
    {
        len++;
    }
    return len;
}

void add(const char* key, int data)
{
    unsigned long hashKey = hash(key);
    HashEntry* newHash = (HashEntry*)malloc(sizeof(HashEntry));

    char* keyAlloc = (char*)malloc(sizeof(char) * (getLen(key) + 1));
    strcpy(keyAlloc, key);
    newHash->key = keyAlloc;
    newHash->data = data;
    newHash->nextChain = NULL;

    if (tb[hashKey] == NULL)
    {
        tb[hashKey] = newHash;
    }
    else
    {
        newHash->nextChain = tb[hashKey];
        tb[hashKey] = newHash;
    }
}

int find(const char* key)
{
    unsigned long hashKey = hash(key);
    HashEntry* curr = tb[hashKey];
    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            return curr->data;
        }
        curr = curr->nextChain;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    add("absdfsdfsdfewfwe", 0);
    add("b", 1);
    add("", 2);
    add("?!", 3);
    add("eewfrwerqtrweasatastasdtasdtds tewtewtwetwetwetwe", 4);
    add("±Â", 5);

    const char* strings[] = { "absdfsdfsdfewfwe", "b", "", "?!", "!?", "eewfrwerqtrweasatastasdtasdtds tewtewtwetwetwetwe", "±Â", "not", "1" };
    for (int i = 0; i < 9; i++)
    {
        printf("data:%2d  key:%s \n", find(strings[i]), strings[i]);
    }



    return 0;
}