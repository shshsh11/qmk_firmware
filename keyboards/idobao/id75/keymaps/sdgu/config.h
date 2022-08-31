/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// #pragma once
// #define COMBO_COUNT 24
#define FORCE_NKRO

#define TAPPING_TERM 200
// 100 is too low of a tapping term, requires too much of a tap, can't really roll
// 150 seems to not have very noticeable delay but is also pretty consistent when wanting to type space
// 200 is somewhat stuttery but also I kind of need to pay attention and type consistently to notice it
#define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
// notes: combo for shift, mod tap everything else
// to test: rolling keypressed
// - all three settings off: does not behave how I want (mod is favored)
// - only HOLD_ON_OTHER_KEY_PRESS on: does not behave how I want (mod is favored)
// - only PERMISSIVE_HOLD on: does not behave how I want (mod is favored)
// - only IGNORE_MOD_TAP_INTERRUPT on: does not behave how I want (bigram is favored, but combo+mod-tap does not lead to capital)
// - IGNORE_MOD_TAP_INTERRUPT and PERMISSIVE_HOLD on: does not behave how I want (current most preferred, bigram is favored, but combo+mod-tap does not lead to capital)
// - IGNORE_MOD_TAP_INTERRUPT and HOLD_ON_OTHER_KEY_PRESS on: does not behave how I want (mod is favored)
// - PERMISSIVE_HOLD and HOLD_ON_OTHER_KEY_PRESS on: does not behave how I want (mod is favored)
// - all three on: does not behave how I want (mod is favored)
#define COMBO_TERM 35
#define COMBO_ONLY_FROM_LAYER 0
// #define COMBO_NO_TIMER
// - COMBO_NO_TIMER on: doesn't seem to have an effect for my use case, I think partially because my combo is short and partially because it's a mod
#define EXTRA_SHORT_COMBOS
// - EXTRA_SHORT_COMBOS on: didn't seem to have any effect, but I can keep it on since my combos are short
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD



// #define TAPPING_FORCE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY

