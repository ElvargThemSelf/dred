// Copyright (C) 2016 David Reid. See included LICENSE file.

// The checkbox control is a box with a check mark and a label. The size of the box is based on the size of the font.

#define DRED_CONTROL_TYPE_CHECKBOX   "dred.common.checkbox"

typedef struct dred_checkbox dred_checkbox;
#define DRED_CHECKBOX(a) ((dred_checkbox*)(a))

typedef void (* dred_checkbox_on_checked_changed_proc)(dred_checkbox* pData);

struct dred_checkbox
{
    // The base control.
    dred_control control;

    char text[64];
    dred_font* pFont;
    dred_gui_font* pSubFont;
    dred_color textColor;
    dred_color bgColor;
    dred_color boxBGColor;
    dred_color boxBGColorHovered;
    dred_color boxBGColorPressed;
    dred_color boxBorderColor;
    dred_color checkColor;
    float borderWidth;
    float padding;
    bool isMouseOver;
    bool isAutoSizeEnabled;
    bool isChecked;
    char varBinding[128];
    dred_checkbox_on_checked_changed_proc onCheckChanged;
};

dred_checkbox* dred_checkbox_create(dred_context* pDred, dred_control* pParent, const char* text, bool checked);
void dred_checkbox_delete(dred_checkbox* pData);

void dred_checkbox_set_text(dred_checkbox* pData, const char* text);
void dred_checkbox_enable_auto_size(dred_checkbox* pData);
void dred_checkbox_disable_auto_size(dred_checkbox* pData);

void dred_checkbox_set_font(dred_checkbox* pData, dred_font* pFont);
void dred_checkbox_set_background_color(dred_checkbox* pData, dred_color color);
void dred_checkbox_set_border_color(dred_checkbox* pData, dred_color color);
void dred_checkbox_set_border_width(dred_checkbox* pData, float width);
void dred_checkbox_set_padding(dred_checkbox* pData, float padding);

void dred_checkbox_check(dred_checkbox* pData);
void dred_checkbox_uncheck(dred_checkbox* pData);
void dred_checkbox_toggle(dred_checkbox* pData);
void dred_checkbox_set_checked(dred_checkbox* pData, bool checked, bool blockEvent);
bool dred_is_checked(dred_checkbox* pData);

void dred_checkbox_set_bind_to_config_var(dred_checkbox* pData, const char* varName);
void dred_checkbox_set_on_checked_changed(dred_checkbox* pData, dred_checkbox_on_checked_changed_proc proc);