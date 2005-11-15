/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 *  Copyright (C) 2004 Hiroyuki Ikezoe
 *  Copyright (C) 2004-2005 Takuro Ashie
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICUoLAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#define SCIM_ANTHY_USE_GTK
#include <scim.h>
#include "scim_anthy_prefs.h"
#include "scim_anthy_intl.h"

namespace scim_anthy {

BoolConfigData config_bool_common [] =
{
    {
        SCIM_ANTHY_CONFIG_SHOW_CANDIDATES_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_CANDIDATES_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_CANDIDATES_LABEL_DEFAULT,
        N_("Show \"_Candidates\" label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CLOSE_CAND_WIN_ON_SELECT,
        SCIM_ANTHY_CONFIG_CLOSE_CAND_WIN_ON_SELECT_DEFAULT,
        SCIM_ANTHY_CONFIG_CLOSE_CAND_WIN_ON_SELECT_DEFAULT,
        N_("Close candidate window when select a candidate _directly"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_LEARN_ON_MANUAL_COMMIT,
        SCIM_ANTHY_CONFIG_LEARN_ON_MANUAL_COMMIT_DEFAULT,
        SCIM_ANTHY_CONFIG_LEARN_ON_MANUAL_COMMIT_DEFAULT,
        N_("Learn on _manual committing"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_LEARN_ON_AUTO_COMMIT,
        SCIM_ANTHY_CONFIG_LEARN_ON_AUTO_COMMIT_DEFAULT,
        SCIM_ANTHY_CONFIG_LEARN_ON_AUTO_COMMIT_DEFAULT,
        N_("Learn on a_uto committing"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_ROMAJI_HALF_SYMBOL,
        SCIM_ANTHY_CONFIG_ROMAJI_HALF_SYMBOL_DEFAULT,
        SCIM_ANTHY_CONFIG_ROMAJI_HALF_SYMBOL_DEFAULT,
        N_("Use half-width characters for _symbols"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_ROMAJI_HALF_NUMBER,
        SCIM_ANTHY_CONFIG_ROMAJI_HALF_NUMBER_DEFAULT,
        SCIM_ANTHY_CONFIG_ROMAJI_HALF_NUMBER_DEFAULT,
        N_("Use half-width characters for _numbers"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_ROMAJI_ALLOW_SPLIT,
        SCIM_ANTHY_CONFIG_ROMAJI_ALLOW_SPLIT_DEFAULT,
        SCIM_ANTHY_CONFIG_ROMAJI_ALLOW_SPLIT_DEFAULT,
        N_("A_llow spliting romaji on editing preedit string"),
        NULL,
        N_("If this check is enabled, you can delete each letter."),
        false,
    },
    {
        SCIM_ANTHY_CONFIG_PREDICT_ON_INPUT,
        SCIM_ANTHY_CONFIG_PREDICT_ON_INPUT_DEFAULT,
        SCIM_ANTHY_CONFIG_PREDICT_ON_INPUT_DEFAULT,
        N_("Show predicted candidates while inputting letters"),
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_USE_DIRECT_KEY_ON_PREDICT,
        SCIM_ANTHY_CONFIG_USE_DIRECT_KEY_ON_PREDICT_DEFAULT,
        SCIM_ANTHY_CONFIG_USE_DIRECT_KEY_ON_PREDICT_DEFAULT,
        N_("Use direct select keys while predicting"),
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHOW_INPUT_MODE_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_INPUT_MODE_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_INPUT_MODE_LABEL_DEFAULT,
        N_("Show _input mode label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHOW_CONVERSION_MODE_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_CONVERSION_MODE_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_CONVERSION_MODE_LABEL_DEFAULT,
        N_("Show _conversion mode label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHOW_TYPING_METHOD_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_TYPING_METHOD_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_TYPING_METHOD_LABEL_DEFAULT,
        N_("Show _typing method label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHOW_PERIOD_STYLE_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_PERIOD_STYLE_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_PERIOD_STYLE_LABEL_DEFAULT,
        N_("Show _period style label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHOW_DICT_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_DICT_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_DICT_LABEL_DEFAULT,
        N_("Show _dictionary menu label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHOW_DICT_ADMIN_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_DICT_ADMIN_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_DICT_ADMIN_LABEL_DEFAULT,
        N_("Show _edit dictionary label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHOW_ADD_WORD_LABEL,
        SCIM_ANTHY_CONFIG_SHOW_ADD_WORD_LABEL_DEFAULT,
        SCIM_ANTHY_CONFIG_SHOW_ADD_WORD_LABEL_DEFAULT,
        N_("Show _add word label"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

IntConfigData config_int_common [] =
{
    {
        SCIM_ANTHY_CONFIG_CAND_WIN_PAGE_SIZE,
        SCIM_ANTHY_CONFIG_CAND_WIN_PAGE_SIZE_DEFAULT,
        SCIM_ANTHY_CONFIG_CAND_WIN_PAGE_SIZE_DEFAULT,
        1, 100, 1,
        N_("Number of candidates to show in a _page:"),
        NULL,
        NULL,
        N_("Specify the number of candidates to show in a page of the candidates window."),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_N_TRIGGERS_TO_SHOW_CAND_WIN,
        SCIM_ANTHY_CONFIG_N_TRIGGERS_TO_SHOW_CAND_WIN_DEFAULT,
        SCIM_ANTHY_CONFIG_N_TRIGGERS_TO_SHOW_CAND_WIN_DEFAULT,
        0, 100, 1,
        N_("Number of _triggers until show:"),
        N_("[times]"),
        NULL,
        N_("The number of times to press a conversion key until show the candidates window."
           "Specify 0 to never show it."),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_NICOLA_TIME,
        SCIM_ANTHY_CONFIG_NICOLA_TIME_DEFAULT,
        SCIM_ANTHY_CONFIG_NICOLA_TIME_DEFAULT,
        5, 1000, 1,
        N_("_Simultaneous pressing time:"),
        N_("[msec]"),
        NULL,
        N_("Time to regard as simultaneous key pressing."),
        NULL,
        false,
    },
    {
        NULL,
        0,
        0,
        0, 0, 0,
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_string_common [] =
{
    {
        SCIM_ANTHY_CONFIG_INPUT_MODE,
        SCIM_ANTHY_CONFIG_INPUT_MODE_DEFAULT,
        SCIM_ANTHY_CONFIG_INPUT_MODE_DEFAULT,
        N_("_Input mode: "),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_TYPING_METHOD,
        SCIM_ANTHY_CONFIG_TYPING_METHOD_DEFAULT,
        SCIM_ANTHY_CONFIG_TYPING_METHOD_DEFAULT,
        N_("Typing _method: "),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONVERSION_MODE,
        SCIM_ANTHY_CONFIG_CONVERSION_MODE_DEFAULT,
        SCIM_ANTHY_CONFIG_CONVERSION_MODE_DEFAULT,
        N_("_Conversion mode: "),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_PERIOD_STYLE,
        SCIM_ANTHY_CONFIG_PERIOD_STYLE_DEFAULT,
        SCIM_ANTHY_CONFIG_PERIOD_STYLE_DEFAULT,
        N_("St_yle of comma and period: "),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SPACE_TYPE,
        SCIM_ANTHY_CONFIG_SPACE_TYPE_DEFAULT,
        SCIM_ANTHY_CONFIG_SPACE_TYPE_DEFAULT,
        N_("_Space type: "),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_TEN_KEY_TYPE,
        SCIM_ANTHY_CONFIG_TEN_KEY_TYPE_DEFAULT,
        SCIM_ANTHY_CONFIG_TEN_KEY_TYPE_DEFAULT,
        N_("Input from _ten key: "),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_BEHAVIOR_ON_PERIOD,
        SCIM_ANTHY_CONFIG_BEHAVIOR_ON_PERIOD_DEFAULT,
        SCIM_ANTHY_CONFIG_BEHAVIOR_ON_PERIOD_DEFAULT,
        N_("_Behavior on a comma or a period:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_LEFT_THUMB_SHIFT_KEY,
        SCIM_ANTHY_CONFIG_LEFT_THUMB_SHIFT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_LEFT_THUMB_SHIFT_KEY_DEFAULT,
        N_("_Left thumb shift keys:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_RIGHT_THUMB_SHIFT_KEY,
        SCIM_ANTHY_CONFIG_RIGHT_THUMB_SHIFT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_RIGHT_THUMB_SHIFT_KEY_DEFAULT,
        N_("_Right thumb shift keys:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_COMMIT_REVERSE_LEARN_KEY,
        SCIM_ANTHY_CONFIG_COMMIT_REVERSE_LEARN_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_COMMIT_REVERSE_LEARN_KEY_DEFAULT,
        N_("_Commit:"),
        N_("Select commit keys"),
        N_("The key events to commit the preedit string "
           "with reversing the preference of learning. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_COMMIT_FIRST_SEGMENT_REVERSE_LEARN_KEY,
        SCIM_ANTHY_CONFIG_COMMIT_FIRST_SEGMENT_REVERSE_LEARN_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_COMMIT_FIRST_SEGMENT_REVERSE_LEARN_KEY_DEFAULT,
        N_("Commit the _first segment:"),
        N_("Select keys to commit the first segment"),
        N_("The key events to commit the first segment "
           "with reversing the preference of learning. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_COMMIT_SELECTED_SEGMENT_REVERSE_LEARN_KEY,
        SCIM_ANTHY_CONFIG_COMMIT_SELECTED_SEGMENT_REVERSE_LEARN_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_COMMIT_SELECTED_SEGMENT_REVERSE_LEARN_KEY_DEFAULT,
        N_("Commit the _selected segment:"),
        N_("Select keys to commit the selected segment"),
        N_("The key events to commit the selected segment "
           "with reversing the preference of learning. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_DICT_ADMIN_COMMAND,
        SCIM_ANTHY_CONFIG_DICT_ADMIN_COMMAND_DEFAULT,
        SCIM_ANTHY_CONFIG_DICT_ADMIN_COMMAND_DEFAULT,
        N_("\"_Edit dictionary\" command:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_ADD_WORD_COMMAND,
        SCIM_ANTHY_CONFIG_ADD_WORD_COMMAND_DEFAULT,
        SCIM_ANTHY_CONFIG_ADD_WORD_COMMAND_DEFAULT,
        N_("\"_Add word\" command:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_PREEDIT_STYLE,
        SCIM_ANTHY_CONFIG_PREEDIT_STYLE_DEFAULT,
        SCIM_ANTHY_CONFIG_PREEDIT_STYLE_DEFAULT,
        N_("_Preedit string:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONVERSION_STYLE,
        SCIM_ANTHY_CONFIG_CONVERSION_STYLE_DEFAULT,
        SCIM_ANTHY_CONFIG_CONVERSION_STYLE_DEFAULT,
        N_("_Conversion string:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_STYLE,
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_STYLE_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_STYLE_DEFAULT,
        N_("_Selected segment:"),
        NULL,
        NULL,
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_edit [] =
{
    {
        SCIM_ANTHY_CONFIG_INSERT_SPACE_KEY,
        SCIM_ANTHY_CONFIG_INSERT_SPACE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_INSERT_SPACE_KEY_DEFAULT,
        N_("Insert space"),
        N_("Select inserting space keys"),
        N_("The key events to insert a space. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_INSERT_ALT_SPACE_KEY,
        SCIM_ANTHY_CONFIG_INSERT_ALT_SPACE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_INSERT_ALT_SPACE_KEY_DEFAULT,
        N_("Insert alternative space"),
        N_("Select inserting alternative space keys"),
        N_("The key events to insert a alternative space. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_INSERT_HALF_SPACE_KEY,
        SCIM_ANTHY_CONFIG_INSERT_HALF_SPACE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_INSERT_HALF_SPACE_KEY_DEFAULT,
        N_("Insert half space"),
        N_("Select inserting half width space keys"),
        N_("The key events to insert a half width space. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_INSERT_WIDE_SPACE_KEY,
        SCIM_ANTHY_CONFIG_INSERT_WIDE_SPACE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_INSERT_WIDE_SPACE_KEY_DEFAULT,
        N_("Insert wide space"),
        N_("Select inserting wide space keys"),
        N_("The key events to insert a wide space. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_BACKSPACE_KEY,
        SCIM_ANTHY_CONFIG_BACKSPACE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_BACKSPACE_KEY_DEFAULT,
        N_("Backspace"),
        N_("Select backspace keys"),
        N_("The key events to delete a character before caret. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_DELETE_KEY,
        SCIM_ANTHY_CONFIG_DELETE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_DELETE_KEY_DEFAULT,
        N_("Delete"),
        N_("Select delete keys"),
        N_("The key events to delete a character after caret. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_COMMIT_KEY,
        SCIM_ANTHY_CONFIG_COMMIT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_COMMIT_KEY_DEFAULT,
        N_("Commit"),
        N_("Select commit keys"),
        N_("The key events to commit the preedit string. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONVERT_KEY,
        SCIM_ANTHY_CONFIG_CONVERT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONVERT_KEY_DEFAULT,
        N_("Convert"),
        N_("Select convert keys"),
        N_("The key events to convert the preedit string to kanji. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_PREDICT_KEY,
        SCIM_ANTHY_CONFIG_PREDICT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_PREDICT_KEY_DEFAULT,
        N_("Predict"),
        N_("Select predict keys"),
        N_("The key events to predict a word or sentence from already inserted text. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CANCEL_KEY,
        SCIM_ANTHY_CONFIG_CANCEL_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CANCEL_KEY_DEFAULT,
        N_("Cancel"),
        N_("Select cancel keys"),
        N_("The key events to cancel preediting or converting. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CANCEL_ALL_KEY,
        SCIM_ANTHY_CONFIG_CANCEL_ALL_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CANCEL_ALL_KEY_DEFAULT,
        N_("Cancel all"),
        N_("Select cancel all keys"),
        N_("The key events to return to initial state. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_RECONVERT_KEY,
        SCIM_ANTHY_CONFIG_RECONVERT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_RECONVERT_KEY_DEFAULT,
        N_("Reconvert"),
        N_("Select reconvert keys"),
        N_("The key events to reconvert the commited string in selection. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_DO_NOTHING_KEY,
        SCIM_ANTHY_CONFIG_DO_NOTHING_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_DO_NOTHING_KEY_DEFAULT,
        N_("Do nothing"),
        N_("Select do nothing keys"),
        N_("The key events to eat and do nothing anymore. "
           "For example, it can be used to disable space key completely."),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_caret [] =
{
    {
        SCIM_ANTHY_CONFIG_MOVE_CARET_FIRST_KEY,
        SCIM_ANTHY_CONFIG_MOVE_CARET_FIRST_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_MOVE_CARET_FIRST_KEY_DEFAULT,
        N_("Move to first"),
        N_("Select move caret to first keys"),
        N_("The key events to move the caret to the first of preedit string. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_MOVE_CARET_LAST_KEY,
        SCIM_ANTHY_CONFIG_MOVE_CARET_LAST_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_MOVE_CARET_LAST_KEY_DEFAULT,
        N_("Move to last"),
        N_("Select move caret to last keys"),
        N_("The key events to move the caret to the last of the preedit string. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_MOVE_CARET_FORWARD_KEY,
        SCIM_ANTHY_CONFIG_MOVE_CARET_FORWARD_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_MOVE_CARET_FORWARD_KEY_DEFAULT,
        N_("Move to forward"),
        N_("Select move caret to forward keys"),
        N_("The key events to move the caret to forward. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_MOVE_CARET_BACKWARD_KEY,
        SCIM_ANTHY_CONFIG_MOVE_CARET_BACKWARD_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_MOVE_CARET_BACKWARD_KEY_DEFAULT,
        N_("Move to backward"),
        N_("Select move caret to backward keys"),
        N_("The key events to move the caret to backward. "),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_segments [] =
{
    {
        SCIM_ANTHY_CONFIG_SELECT_FIRST_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_SELECT_FIRST_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_FIRST_SEGMENT_KEY_DEFAULT,
        N_("Select the first segment"),
        N_("Select keys to select the first segment"),
        N_("The key events to select the first segment. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_LAST_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_SELECT_LAST_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_LAST_SEGMENT_KEY_DEFAULT,
        N_("Select the last segment"),
        N_("Select keys to select the last segment"),
        N_("The key events to select the the last segment. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_NEXT_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_SELECT_NEXT_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_NEXT_SEGMENT_KEY_DEFAULT,
        N_("Select the next segment"),
        N_("Select keys to select the next segment"),
        N_("The key events to select the next segment. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_PREV_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_SELECT_PREV_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_PREV_SEGMENT_KEY_DEFAULT,
        N_("Select the previous segment"),
        N_("Select keys to select the previous segment"),
        N_("The key events to select the previous segment. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SHRINK_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_SHRINK_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SHRINK_SEGMENT_KEY_DEFAULT,
        N_("Shrink the segment"),
        N_("Select keys to shrink the segment"),
        N_("The key events to shrink the selected segment. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_EXPAND_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_EXPAND_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_EXPAND_SEGMENT_KEY_DEFAULT,
        N_("Expand the segment"),
        N_("Select keys to expand the segment"),
        N_("The key events to expand the selected segment. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_COMMIT_FIRST_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_COMMIT_FIRST_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_COMMIT_FIRST_SEGMENT_KEY_DEFAULT,
        N_("Commit the first segment"),
        N_("Select keys to commit the first segment"),
        N_("The key events to commit the first segment. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_COMMIT_SELECTED_SEGMENT_KEY,
        SCIM_ANTHY_CONFIG_COMMIT_SELECTED_SEGMENT_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_COMMIT_SELECTED_SEGMENT_KEY_DEFAULT,
        N_("Commit the selected segment"),
        N_("Select keys to commit the selected segment"),
        N_("The key events to commit the selected segment. "),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_candidates [] =
{
    {
        SCIM_ANTHY_CONFIG_SELECT_FIRST_CANDIDATE_KEY,
        SCIM_ANTHY_CONFIG_SELECT_FIRST_CANDIDATE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_FIRST_CANDIDATE_KEY_DEFAULT,
        N_("First candidate"),
        N_("Select the first candidate keys"),
        N_("The key events to select the first candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_LAST_CANDIDATE_KEY,
        SCIM_ANTHY_CONFIG_SELECT_LAST_CANDIDATE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_LAST_CANDIDATE_KEY_DEFAULT,
        N_("Last candidate"),
        N_("Select the last candidate keys"),
        N_("The key events to the select last candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_NEXT_CANDIDATE_KEY,
        SCIM_ANTHY_CONFIG_SELECT_NEXT_CANDIDATE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_NEXT_CANDIDATE_KEY_DEFAULT,
        N_("Next candidate"),
        N_("Select the next candidate keys"),
        N_("The key events to select the next candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_PREV_CANDIDATE_KEY,
        SCIM_ANTHY_CONFIG_SELECT_PREV_CANDIDATE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_PREV_CANDIDATE_KEY_DEFAULT,
        N_("Previous candidate"),
        N_("Select the previous candidate keys"),
        N_("The key events to select the previous candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CANDIDATES_PAGE_UP_KEY,
        SCIM_ANTHY_CONFIG_CANDIDATES_PAGE_UP_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CANDIDATES_PAGE_UP_KEY_DEFAULT,
        N_("Page up"),
        N_("Select page up candidates keys"),
        N_("The key events to switch candidates page up. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CANDIDATES_PAGE_DOWN_KEY,
        SCIM_ANTHY_CONFIG_CANDIDATES_PAGE_DOWN_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CANDIDATES_PAGE_DOWN_KEY_DEFAULT,
        N_("Page down"),
        N_("Select page down candidates keys"),
        N_("The key events to switch candidates page down. "),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_direct_select [] =
{
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_1_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_1_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_1_KEY_DEFAULT,
        N_("1st candidate"),
        N_("Select keys to select 1st candidate"),
        N_("The key events to select the 1st candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_2_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_2_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_2_KEY_DEFAULT,
        N_("2nd candidate"),
        N_("Select keys to select 2nd candidate"),
        N_("The key events to select the 2nd candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_3_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_3_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_3_KEY_DEFAULT,
        N_("3rd candidate"),
        N_("Select keys to select 3rd candidate"),
        N_("The key events to select the 3rd candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_4_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_4_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_4_KEY_DEFAULT,
        N_("4th candidate"),
        N_("Select keys to select 4th candidate"),
        N_("The key events to select the 4th candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_5_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_5_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_5_KEY_DEFAULT,
        N_("5th candidate"),
        N_("Select keys to select 5th candidate"),
        N_("The key events to select the 5th candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_6_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_6_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_6_KEY_DEFAULT,
        N_("6th candidate"),
        N_("Select keys to select 6th candidate"),
        N_("The key events to select the 6th candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_7_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_7_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_7_KEY_DEFAULT,
        N_("7th candidate"),
        N_("Select keys to select 7th candidate"),
        N_("The key events to select the 7th candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_8_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_8_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_8_KEY_DEFAULT,
        N_("8th candidate"),
        N_("Select keys to select 8th candidate"),
        N_("The key events to select the 8th candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_9_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_9_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_9_KEY_DEFAULT,
        N_("9th candidate"),
        N_("Select keys to select 9th candidate"),
        N_("The key events to select the 9th candidate. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_10_KEY,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_10_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECT_CANDIDATE_10_KEY_DEFAULT,
        N_("10th candidate"),
        N_("Select keys to select 10th candidate"),
        N_("The key events to select the 10th candidate. "),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_converting [] =
{
    {
        SCIM_ANTHY_CONFIG_CONV_CHAR_TYPE_FORWARD_KEY,
        SCIM_ANTHY_CONFIG_CONV_CHAR_TYPE_FORWARD_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_CHAR_TYPE_FORWARD_KEY_DEFAULT,
        N_("Convert character type to forward"),
        N_("Select keys to convert character type to forward"),
        N_("Rotate character type forward."),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONV_CHAR_TYPE_BACKWARD_KEY,
        SCIM_ANTHY_CONFIG_CONV_CHAR_TYPE_BACKWARD_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_CHAR_TYPE_BACKWARD_KEY_DEFAULT,
        N_("Convert character type to backward"),
        N_("Select keys to convert character type to backward"),
        N_("Rotate character type backward."),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONV_TO_HIRAGANA_KEY,
        SCIM_ANTHY_CONFIG_CONV_TO_HIRAGANA_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_TO_HIRAGANA_KEY_DEFAULT,
        N_("Convert to hiragana"),
        N_("Select keys to convert to hiragana"),
        N_("The key events to convert the preedit string to hiragana. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONV_TO_KATAKANA_KEY,
        SCIM_ANTHY_CONFIG_CONV_TO_KATAKANA_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_TO_KATAKANA_KEY_DEFAULT,
        N_("Convert to katakana"),
        N_("Select keys to convert to katakana"),
        N_("The key events to convert the preedit string to katakana. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONV_TO_HALF_KEY,
        SCIM_ANTHY_CONFIG_CONV_TO_HALF_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_TO_HALF_KEY_DEFAULT,
        N_("Convert to half width"),
        N_("Select keys to convert to half width"),
        N_("The key events to convert the preedit string to half width. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONV_TO_HALF_KATAKANA_KEY,
        SCIM_ANTHY_CONFIG_CONV_TO_HALF_KATAKANA_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_TO_HALF_KATAKANA_KEY_DEFAULT,
        N_("Convert to half katakana"),
        N_("Select keys to convert to half width katakana"),
        N_("The key events to convert the preedit string to half width katakana. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONV_TO_WIDE_LATIN_KEY,
        SCIM_ANTHY_CONFIG_CONV_TO_WIDE_LATIN_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_TO_WIDE_LATIN_KEY_DEFAULT,
        N_("Convert to wide latin"),
        N_("Select keys to convert to wide latin"),
        N_("The key events to convert the preedit string to wide latin. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONV_TO_LATIN_KEY,
        SCIM_ANTHY_CONFIG_CONV_TO_LATIN_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CONV_TO_LATIN_KEY_DEFAULT,
        N_("Convert to latin"),
        N_("Select keys to convert to latin"),
        N_("The key events to convert the preedit string to latin. "),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_mode [] =
{
    {
        SCIM_ANTHY_CONFIG_ON_OFF_KEY,
        SCIM_ANTHY_CONFIG_ON_OFF_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_ON_OFF_KEY_DEFAULT,
        N_("Toggle on/off"),
        N_("Select toggle on/off keys"),
        N_("The key events to toggle on/off Japanese mode. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CIRCLE_INPUT_MODE_KEY,
        SCIM_ANTHY_CONFIG_CIRCLE_INPUT_MODE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CIRCLE_INPUT_MODE_KEY_DEFAULT,
        N_("Circle input mode"),
        N_("Select circle input mode keys"),
        N_("The key events to circle input mode. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CIRCLE_KANA_MODE_KEY,
        SCIM_ANTHY_CONFIG_CIRCLE_KANA_MODE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CIRCLE_KANA_MODE_KEY_DEFAULT,
        N_("Circle kana mode"),
        N_("Select circle kana mode keys"),
        N_("The key events to circle kana mode. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_LATIN_MODE_KEY,
        SCIM_ANTHY_CONFIG_LATIN_MODE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_LATIN_MODE_KEY_DEFAULT,
        N_("Latin mode"),
        N_("Select Latin mode keys"),
        N_("The key events to switch input mode to Latin. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_WIDE_LATIN_MODE_KEY,
        SCIM_ANTHY_CONFIG_WIDE_LATIN_MODE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_WIDE_LATIN_MODE_KEY_DEFAULT,
        N_("Wide Latin mode"),
        N_("Select wide Latin mode keys"),
        N_("The key events to switch input mode to wide Latin. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_HIRAGANA_MODE_KEY,
        SCIM_ANTHY_CONFIG_HIRAGANA_MODE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_HIRAGANA_MODE_KEY_DEFAULT,
        N_("Hiragana mode"),
        N_("Select hiragana mode keys"),
        N_("The key events to switch input mode to hiragana. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_KATAKANA_MODE_KEY,
        SCIM_ANTHY_CONFIG_KATAKANA_MODE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_KATAKANA_MODE_KEY_DEFAULT,
        N_("Katakana mode"),
        N_("Select katakana mode keys"),
        N_("The key events to switch input mode to katakana. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_HALF_KATAKANA_MODE_KEY,
        SCIM_ANTHY_CONFIG_HALF_KATAKANA_MODE_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_HALF_KATAKANA_MODE_KEY_DEFAULT,
        N_("Half katakana mode"),
        N_("Select half katakana mode keys"),
        N_("The key events to switch input mode to half katakana. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CIRCLE_TYPING_METHOD_KEY,
        SCIM_ANTHY_CONFIG_CIRCLE_TYPING_METHOD_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_CIRCLE_TYPING_METHOD_KEY_DEFAULT,
        N_("Circle typing method"),
        N_("Select circle typing method keys"),
        N_("The key events to circle typing method. "),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

StringConfigData config_keyboards_dict [] =
{
    {
        SCIM_ANTHY_CONFIG_DICT_ADMIN_KEY,
        SCIM_ANTHY_CONFIG_DICT_ADMIN_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_DICT_ADMIN_KEY_DEFAULT,
        N_("Edit dictionary"),
        N_("Select edit dictionary keys"),
        N_("The key events to launch dictionary administration tool. "),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_ADD_WORD_KEY,
        SCIM_ANTHY_CONFIG_ADD_WORD_KEY_DEFAULT,
        SCIM_ANTHY_CONFIG_ADD_WORD_KEY_DEFAULT,
        N_("Add a word"),
        N_("Select add a word keys"),
        N_("The key events to launch the tool to add a word. "),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};

ColorConfigData config_color_common [] =
{
    {
        SCIM_ANTHY_CONFIG_PREEDIT_FG_COLOR,
        SCIM_ANTHY_CONFIG_PREEDIT_FG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_PREEDIT_FG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_PREEDIT_BG_COLOR,
        SCIM_ANTHY_CONFIG_PREEDIT_BG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_PREEDIT_BG_COLOR_DEFAULT,
        N_("Color:"),
        N_("The color of preediting text"),
        N_("The color of preediting text"),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_CONVERSION_FG_COLOR,
        SCIM_ANTHY_CONFIG_CONVERSION_FG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_CONVERSION_FG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_CONVERSION_BG_COLOR,
        SCIM_ANTHY_CONFIG_CONVERSION_BG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_CONVERSION_BG_COLOR_DEFAULT,
        N_("Color:"),
        N_("The color of conversion text"),
        N_("The color of conversion text"),
        NULL,
        false,
    },
    {
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_FG_COLOR,
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_FG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_FG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_BG_COLOR,
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_BG_COLOR_DEFAULT,
        SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_BG_COLOR_DEFAULT,
        N_("Color:"),
        N_("The color of selected segment text"),
        N_("The color of selected segment text in the conversion text"),
        NULL,
        false,
    },
    {
        NULL,
        "",
        "",
        NULL,
        "",
        "",
        NULL,
        NULL,
        NULL,
        NULL,
        false,
    },
};
}
