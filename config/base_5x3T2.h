/*
 * Copyright (c) 2021 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define APT 0
#define NAV 1
#define NUM 2
#define FUN 3
#define SYM 4
#define BTC 5

// &lt {
//     quick_tap_ms = <200>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_sch: macro_sch {
            label = "Macro_SCH";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp S &kp C &kp H>;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <120>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
        COMBO(delete, &kp DEL, 30 31)
        COMBO(escape, &kp ESC, 32 33)
        COMBO(grave, &kp GRAVE, 8 9)
/* usually on base layer */
        // COMBO(q, &kp Q, 2 3)
        // COMBO(z, &kp Z, 21 22)
        // COMBO(v, &kp V, 1 2)
        // COMBO(sch, &macro_sch, 1 3)
        // COMBO(slash, &kp SLASH, 27 28)
        // COMBO(dash, &kp MINUS, 26 27)
        // COMBO(enter, &kp ENTER, 26 27 28)
        // COMBO(esc, &kp ESC, 22 23)
/* parentheticals */
        // COMBO(lbrc, &kp LBRC, 1 11)
        // COMBO(lbkt, &kp LBKT, 2 12)
        // COMBO(lpar, &kp LPAR, 3 13)
        // COMBO(lt, &kp LT, 4 14)
        // COMBO(gt, &kp GT, 5 15)
        // COMBO(rpar, &kp RPAR, 6 16)
        // COMBO(rbkt, &kp RBKT, 7 17)
        // COMBO(rbrc, &kp RBRC, 8 18)
/* caps */
        // COMBO(caps, &caps_word, 13 16)
        // COMBO(capslock, &kp CAPSLOCK, 1 8)
/* deletion */
        // COMBO(bspc, &kp BSPC, 6 7)
        // COMBO(del, &kp DEL, 7 8)
        // COMBO(delword, &kp LC(BSPC), 6 8)
    };
};

/ {
    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 32 33>;
        };

        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 31>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23>;
        };

        lpar_shft: lpar_shft {
            compatible = "zmk,behavior-mod-morph";
            label = "LPAR_SHFT";
            #binding-cells = <0>;
            bindings = <&kp LPAR>, <&kp RPAR>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };

        lbkt_shft: lbkt_shft {
            compatible = "zmk,behavior-mod-morph";
            label = "LBKT_SHFT";
            #binding-cells = <0>;
            bindings = <&kp LBKT>, <&kp RBKT>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };

        lbrc_shft: lbrc_shft {
            compatible = "zmk,behavior-mod-morph";
            label = "LBRC_SHFT";
            #binding-cells = <0>;
            bindings = <&kp LBRC>, <&kp RBRC>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
