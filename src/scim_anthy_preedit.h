/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 *  Copyright (C) 2004 Takuro Ashie
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __SCIM_ANTHY_PREEDIT_H__
#define __SCIM_ANTHY_PREEDIT_H__

#define Uses_SCIM_ICONV
#include <anthy/anthy.h>
#include <scim.h>
#include <scim_attribute.h>
#include <scim_event.h>
#include <scim_lookup_table.h>
#include "scim_anthy_key2kana_convertor.h"

using namespace scim;

typedef enum {
    MODE_HIRAGANA,
    MODE_KATAKANA,
    MODE_HALF_KATAKANA,
    MODE_LATIN,
    MODE_WIDE_LATIN,
} InputMode;

typedef enum {
    CANDIDATE_NORMAL        = 0,
    CANDIDATE_LATIN         = -1,
    CANDIDATE_WIDE_LATIN    = -2,
    CANDIDATE_HIRAGANA      = -3,
    CANDIDATE_KATAKANA      = -4,
    CANDIDATE_HALF_KATAKANA = -5,
    LAST_SPECIAL_CANDIDATE  = -6,
} CandidateType;

typedef enum {
    TEN_KEY_HALF,
    TEN_KEY_WIDE,
    TEN_KEY_FOLLOW_MODE,
} TenKeyType;

typedef enum {
    PREEDIT_CURRENT,
    PREEDIT_RAW_KEY,
    PREEDIT_NO_CONVERSION,
    PREEDIT_NO_CONVERSION_HIRAGANA,
    PREEDIT_CONVERSION,
} AnthyPreeditStringType;

class AnthyPreeditSegment
{
public:
    String     key;
    WideString kana;

public:
    AnthyPreeditSegment (void);
    virtual ~AnthyPreeditSegment ();

#if 0
    void split    (void);
    void is_valid (void);
    void to_valid (void);
#endif
};

typedef std::vector<AnthyPreeditSegment> AnthyPreeditSegments;

class AnthyPreedit
{
public:
    AnthyPreedit (AnthyKey2KanaTableSet & tables);
    virtual ~AnthyPreedit ();

    // getting status
    virtual unsigned int  get_length             (AnthyPreeditStringType type = PREEDIT_CURRENT);
    virtual WideString    get_string             (AnthyPreeditStringType type = PREEDIT_CURRENT);
    virtual AttributeList get_attribute_list     (AnthyPreeditStringType type = PREEDIT_CURRENT);

    virtual bool          is_preediting          (void);
    virtual bool          is_converting          (void);
    virtual bool          is_kana_converting     (void);

    // manipulating the preedit string
    virtual bool          can_process            (const KeyEvent & key);
    // return true if commiting is needed.
    virtual bool          append                 (const KeyEvent & key);
    virtual void          erase                  (bool backward = true);
    virtual void          flush_pending          (void);

    // manipulating the conversion string
    virtual void          convert                (CandidateType type = CANDIDATE_NORMAL);
    virtual void          revert                 (void);
    virtual void          commit                 (int  segment_id = -1,
                                                  bool lean       = true);

    // segments of the converted sentence
    virtual int           get_nr_segments        (void);
    virtual WideString    get_segment_string     (int segment_id = -1);
    virtual int           get_selected_segment   (void);
    virtual void          select_segment         (int segment_id);
    virtual int           get_segment_size       (int segment_id = -1);
    virtual void          resize_segment         (int relative_size,
                                                  int segment_id = -1);

    // candidates for a segment
    virtual void          setup_lookup_table     (CommonLookupTable &table,
                                                  int segment_id = -1);
    virtual int           get_selected_candidate (int segment_id = -1);
    virtual void          select_candidate       (int candidate_id,
                                                  int segment_id = -1);

    // manipulating the caret
    virtual unsigned int  get_caret_pos          (void);
    virtual void          set_caret_pos          (unsigned int pos);
    virtual void          move_caret             (int len);

    // clear all string
    virtual void          clear                  (void);

    // preference
    virtual void          set_input_mode         (InputMode mode);
    virtual InputMode     get_input_mode         (void);
    virtual void          set_ten_key_type       (TenKeyType type);
    virtual TenKeyType    get_ten_key_type       (void);
    virtual void          set_auto_convert       (bool autoconv);
    virtual bool          get_auto_convert       (void);

private:
    unsigned int  get_preedit_length             (void);
    WideString    get_preedit_string             (void);
    WideString    get_preedit_string_as_hiragana (void);

    bool          append_str                     (const String & str);
    void          convert_kana                   (CandidateType type);
    void          create_conversion_string       (void);
    void          get_kana_substr                (WideString & substr,
                                                  unsigned int start,
                                                  unsigned int end,
                                                  CandidateType type);
    void          reset_pending                  (void);
    bool          is_comma_or_period             (const String & str);

private:
    // converter objects
    AnthyKey2KanaTableSet  &m_key2kana_tables;
    AnthyKey2KanaConvertor  m_key2kana;
    IConvert                m_iconv;
    anthy_context_t         m_anthy_context;

    // mode flags
    InputMode               m_input_mode;
    TenKeyType              m_ten_key_type;
    bool                    m_auto_convert;

    // raw key code & preedit string
    AnthyPreeditSegments    m_char_list;      // whole preedit characters includes commited one.
                                              // start position of non-commited character is
                                              // pointed by m_start_segment_pos.
    unsigned int            m_start_char;     // to skip already commited characters.
                                              // FIXME!! not implemented yet.
    unsigned int            m_char_caret;     // relative position from m_start_char.

    // real position of the caret
    unsigned int            m_caret;          // relative position from m_start_segment_pos.

    // conversion string
    WideString        m_conv_string;          // conversion string for non-commited segments.
    AttributeList     m_conv_attrs;           // attributes for non-commited segments.
    std::vector<int>  m_selected_candidates;  // candidates ID for all non-commited segments.
    int               m_start_segment_id;     // to skip segments which were already commited.
    int               m_start_segment_pos;    // to skip characters which were already commited.
    int               m_selected_segment_id;  // relative position from m_start_segment_id
    int               m_selected_segment_pos; // relative position from m_start_segment_pos
    bool              m_kana_converting;      // true if whole string is now converting to a
                                              // special candidate.
};

#endif /* __SCIM_ANTHY_PREEDIT_H__ */
/*
vi:ts=4:nowrap:ai:expandtab
*/
