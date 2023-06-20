/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IBubleSort
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IBubleSort
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_BUBLESORT_H__
#define __I_BUBLESORT_H__

#include "IEcoBase1.h"

/* IBubleSort IID = {87CE3954-00A1-4271-A107-EB2788B31103} */
#ifndef __IID_IBubleSort
static const UGUID IID_IBubleSort = {0x01, 0x10, 0x87, 0xCE, 0x39, 0x54, 0x00, 0xA1, 0x42, 0x71, 0xA1, 0x07, 0xEB, 0x27, 0x88, 0xB3, 0x11, 0x03};
#endif /* __IID_IBubleSort */

typedef struct IBubleSortVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ struct IBubleSort* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ struct IBubleSort* me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ struct IBubleSort* me);

    /* IBubleSort */
    void (ECOCALLMETHOD *MyFunction)(/* in */ struct IBubleSort* me, void * first, size_t size, size_t sizeType, int (ECOCDECLMETHOD * comparator ) (const void * , const void * ));
	int (ECOCDECLMETHOD *compare)(const void *, const void *);

	/* IEcoLab1 */

    void (ECOCALLMETHOD *qsort)(struct IEcoLab1 *me, void *base, size_t num, size_t size, int (ECOCDECLMETHOD *compare)(const void *, const void *));


} IBubleSortVTbl, *IBubleSortVTblPtr;

interface IBubleSort {
    struct IBubleSortVTbl *pVTbl;
} IBubleSort;


#endif /* __I_BUBLESORT_H__ */
