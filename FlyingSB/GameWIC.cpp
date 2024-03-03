#include "GameWIC.h"
#include "GameWindow.h"

IWICImagingFactory* GameWIC::s_factory = nullptr;

void GameWIC::Initialize()
{
    CoCreateInstance(
        CLSID_WICImagingFactory,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&s_factory));
}

void GameWIC::Release()
{
    s_factory->Release();
}

ID2D1Bitmap* GameWIC::D2D1BitmapFromFileName(const wchar_t* file_name)
{
    // Create WIC Bitmap Decoder
    IWICBitmapDecoder* decoder = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;

    s_factory->CreateDecoderFromFilename(
        file_name,
        nullptr,
        GENERIC_READ,
        WICDecodeMetadataCacheOnDemand,
        &decoder);

    if (!decoder) // 파일이 존재하지 않는 경우
        return nullptr;

    decoder->GetFrame(0, &frame);
    decoder->Release();

    // Create WIC Format Converter
    IWICFormatConverter* converter = nullptr;
    s_factory->CreateFormatConverter(&converter);

    converter->Initialize(
        frame,
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        nullptr,
        0.f,
        WICBitmapPaletteTypeCustom);

    frame->Release();

    // Create D2D1 Bitmap
    ID2D1Bitmap* bitmap = nullptr;
    GameWindow::RenderTarget()->CreateBitmapFromWicBitmap(
        converter, 
        &bitmap);

    converter->Release();

    return bitmap;
}

namespace GameUI
{
    ID2D1Bitmap* D2D1BitmapFromFileName(const wchar_t* file_name)
    {
        return GameWIC::D2D1BitmapFromFileName(file_name);
    }
}