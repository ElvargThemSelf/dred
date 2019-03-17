// Copyright (C) 2019 David Reid. See included LICENSE file.

dtk_bool32 dred_image_library_init__stock_images(dred_image_library* pLibrary)
{
    assert(pLibrary != NULL);

    // NOTE: Order is important. SVGs come first, then raster images. The reason is the order in which IDs are generated by the code generation tool.
    dtk_uint32 runningIndex = 0;

    // SVG images.
    for (dtk_uint32 i = 0; i < DRED_STOCK_IMAGE_COUNT_SVG; ++i) {
        if (dtk_image_init_svg(&pLibrary->pDred->tk, g_StockImagesSVG[i].pSVGData, &pLibrary->pStockImages[runningIndex]) != DTK_SUCCESS) {
            dtk_zero_object(&pLibrary->pStockImages[runningIndex]);    // Failed to initialize the image. Zero it out. TODO: Replace this with a default fallback.
        }

        runningIndex += 1;
    }

    // Raster images.
    for (dtk_uint32 i = 0; i < DRED_STOCK_IMAGE_COUNT_RASTER; ++i) {
        if (dtk_image_init_raster(&pLibrary->pDred->tk, g_StockImagesRaster[i].width, g_StockImagesRaster[i].height, g_StockImagesRaster[i].width*4, g_StockImagesRaster[i].pImageData, &pLibrary->pStockImages[runningIndex]) != DTK_SUCCESS) {
            dtk_zero_object(&pLibrary->pStockImages[runningIndex]);    // Failed to initialize the image. Zero it out. TODO: Replace this with a default fallback.
        }

        runningIndex += 1;
    }

    return DTK_TRUE;
}


dtk_bool32 dred_image_library_init(dred_image_library* pLibrary, dred_context* pDred)
{
    if (pLibrary == NULL) {
        return DTK_FALSE;
    }

    pLibrary->pDred = pDred;
    pLibrary->imageBufferSize = 0;
    pLibrary->imageCount = 0;
    pLibrary->pImages = NULL;

    return dred_image_library_init__stock_images(pLibrary);
}

void dred_image_library_uninit(dred_image_library* pLibrary)
{
    if (pLibrary == NULL) {
        return;
    }

#if 0
    while (pLibrary->imageCount > 0) {
        dred_image_library__delete_image_for_real(pLibrary, pLibrary->pImages[pLibrary->imageCount-1]);
    }
#endif

    dtk_free(pLibrary->pImages);
}


#if 0
dred_image* dred_image_library_create_image(dred_image_library* pLibrary, unsigned int id, const dred_image_desc* pDesc, size_t descCount)
{
    dred_image* pImage = dred_image_library__create_image_for_real(pLibrary, id, pDesc, descCount);
    if (pImage == NULL) {
        return NULL;
    }

    assert(pImage != NULL);

    return pImage;
}

void dred_image_library_delete_image(dred_image_library* pLibrary, dred_image* pImage)
{
    if (pImage == NULL || pImage->referenceCount == 0) {
        return;
    }

    assert(pLibrary == pImage->pLibrary);


    pImage->referenceCount -= 1;
    if (pImage->referenceCount == 0) {
        dred_image_library__delete_image_for_real(pLibrary, pImage);
    }
}
#endif


dtk_image* dred_image_library_get_image_by_id(dred_image_library* pLibrary, unsigned int id)
{
    if (pLibrary == NULL) {
        return NULL;
    }

    // Optimization for stock images. Try DTK stock images first, then dred stock images.
    if (id < DTK_STOCK_IMAGE_COUNT) {
        return dtk_get_stock_image(&pLibrary->pDred->tk, id);
    }

    if (id-DTK_STOCK_IMAGE_COUNT < DRED_STOCK_IMAGE_COUNT) {
        return &pLibrary->pStockImages[id-DTK_STOCK_IMAGE_COUNT];
    }

    for (size_t i = 0; i < pLibrary->imageCount; ++i) {
        if (pLibrary->pImages[i].id == id) {
            return pLibrary->pImages[i].pImage;
        }
    }

    return NULL;
}
