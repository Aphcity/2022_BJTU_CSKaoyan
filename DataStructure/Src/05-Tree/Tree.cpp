/*

        CopyRight By Aphcity
        2021å¹´10æ30æ¥

*/

#include <stdio.h>
#include <stdlib.h>

/* 

        ð³çå­©å­åå¼è¡¨ç¤ºæ³åºæ¬ç»æåæä½

 */

#define ElemType int

typedef struct CSNode
{
    ElemType data;       //ð³çèç¹æ°æ®
    CSNode *firstChild;  //ð³çç¬¬ä¸ä¸ªå­©å­
    CSNode *nextSibling; //ð³çä¸ä¸ä¸ªè¡¨äº²
} CSNode, *CSTree;

/* 

        ð³çå­©å­åå¼è¡¨ç¤ºæ³

 */

bool IsEmptyCSTree(CSTree T)
{
    if (T == NULL)
        return true;
    return false;
}

/* 

        ð³çå­©å­åå¼è¡¨ç¤ºæ³æ±å¶å­ç»ç¹ä¸ªæ°

 */

int N0_NUMBER(CSTree T)
{
    if (IsEmptyCSTree(T))
        return 1;
    int count = 0; //countå­æ¾å¶å­ç»ç¹ä¸ªæ°ï¼n0
    //printf("%d", T->data); //è¾åºð³çæ ¹èç¹æ°æ®
    //å¼å§éåå­æ 
    count += N0_NUMBER(T->nextSibling);
    while (T->firstChild)
    {
        count += N0_NUMBER(T->firstChild);
    }
    return count - 1;
}

/* 

        ð³çå­©å­åå¼è¡¨ç¤ºæ³éå

 */
