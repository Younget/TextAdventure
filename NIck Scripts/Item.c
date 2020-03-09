/******************************************************************************
filename    Item.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Item interface, which is used to manage items in the game.

******************************************************************************/
#include "stdafx.h" /* NULL, printf, malloc/free, strcpy_s */
#include "Item.h" /* Function declarations */








/* Create a new Item object with the provided data */
Item* Item_Create(const char* name, const char* description, bool isCarryable, ItemFunc useFunc, ItemFunc takeFunc, ItemFunc dropFunc, ItemFunc readFunc, ItemFunc smashFunc, ItemFunc typeFunc)
{
	Item *item; /* the new item to be returned */

	/* safety check on required parameters */
	if (name == NULL) 
	{
		return NULL; /* do not create a new object if the parameters are invalid*/
	}

	/* allocate the memory for a new object */
	item = (Item*)malloc(sizeof(Item));
	if (item == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* copy the data from the parameters into the new object */
	strcpy_s(item->name, MAX_ITEM_NAME_LENGTH, name);
	if (description != NULL)
	{
		strcpy_s(item->description, MAX_ITEM_DESCRIPTION_LENGTH, description);
	}
	item->isCarryable = isCarryable;
	item->useFunc = useFunc;
	item->takeFunc = takeFunc;
	item->dropFunc = dropFunc;
	item->readFunc = readFunc;
	item->smashFunc = smashFunc;
	item->typeFunc = typeFunc; 


	/* return the new object */
	return item;
}


/* Free the memory associated with a given Item object */
void Item_Free(Item** itemPtr)
{
	/* safety check on the parameters */
	if ((itemPtr == NULL) || (*itemPtr == NULL)) 
	{
		return;  /* take no action if the parameters are invalid */
	}

	/* free the given item */
	free(*itemPtr);
	
	/* clear the provided pointer */
	*itemPtr = NULL;
}


/* Retrieve the name of the given item */
const char* Item_GetName(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->name : NULL;
}


/* Retrieve the description of the given item */
const char* Item_GetDescription(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->description : NULL;
}


/* Retrieve whether the item is carryable */
bool Item_IsCarryable(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return false (not carryable) */
	return (item != NULL) ? item->isCarryable : false;
}


/* Retrieve the "use" function for this item, if any */
ItemFunc Item_GetUseFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->useFunc : NULL;
}


/* Retrieve the "take" function for this item, if any */
ItemFunc Item_GetTakeFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->takeFunc : NULL;
}


/* Retrieve the "drop" function for this item, if any */
ItemFunc Item_GetDropFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->dropFunc : NULL;
}

/*retrieves the "read" function for item if it exists*/
ItemFunc Item_GetReadFunc(Item* item)
{
	/* return the data if the parameter is not Null, otherwise return NULL*/
	return (item != NULL) ? item->readFunc : NULL;
}

/*retrieves the "type" function for item if it exists*/
ItemFunc Item_GetTypeFunc(Item* item)
{
	/* return the data if the parameter is not Null, otherwise return NULL*/
	return (item != NULL) ? item->typeFunc : NULL;
}

/*retrieves the "smash" function for item if it exists*/
ItemFunc Item_GetSmashFunc(Item* item)
{
	/* return the data if the parameter is not Null, otherwise return NULL*/
	return (item != NULL) ? item->smashFunc : NULL;
}


/* Print a description of the item to standard output */
void Item_Print(Item* item)
{
	const char* description; /* the description of the provided item */

	/* safety check on the parameters */
	if (item == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}
	
	/* get the current description */
	description = Item_GetDescription(item);
	if ((description != NULL) && (strnlen_s(description, MAX_ITEM_DESCRIPTION_LENGTH) > 0))
	{
		/* the item has a non-trival description - output it */
		printf("%s\n", description);
		return;
	}

	/* the item had no useful description, so output its name instead*/
	description = Item_GetName(item);
	printf("You see a %s.\n", description);
}
