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
#define BTC 4
#define SYM 5

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_const: macro_const {
            label = "macro_const";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp C &kp O &kp N &kp S &kp T &kp SPACE>;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <90>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
        COMBO(delete, &kp DEL, 30 31)
        COMBO(fun_esc, &lt FUN ESC, 32 33)
        COMBO(grave, &kp GRAVE, 8 9)
        COMBO(semi, &kp SEMI, 15 25)
        COMBO(dollar, &kp DOLLAR, 5 15)
        COMBO(equal, &kp EQUAL, 6 16)
        COMBO(escape, &kp ESC, 0 10)
        COMBO(lpar, &lpar_shft, 4 14)
        COMBO(rbkt, &lbrc_shft, 14 24)
        COMBO(alt_tab, &kp LA(TAB), 18 33)
        COMBO(f11, &kp F11, 22 30)
        COMBO(f12, &kp F12, 23 30)
        COMBO(del_word, &kp LC(BSPC), 13 30)
        COMBO(const, &macro_const, 1 3)
        COMBO(caps, &caps_word, 20 29)
    };
};

/ {
    behaviors {
        mt_205: mt_205 {
            compatible = "zmk,behavior-hold-tap";
            label = "mt_205";
            #binding-cells =<2>;
            flavor = "tap-preferred";
            tapping-term-ms = <205>;
            quick-tap-ms = <120>;
            require-prior-idle-ms = <100>;
            bindings = <&kp>, <&kp>;
        };

        mt_90: mt_90 {
            compatible = "zmk,behavior-hold-tap";
            label = "mt_90";
            #binding-cells =<2>;
            flavor = "balanced";
            tapping-term-ms = <90>;
            quick-tap-ms = <90>;
            bindings = <&kp>, <&kp>;
        };

        lt_150: lt_150 {
            compatible = "zmk,behavior-hold-tap";
            label = "lt_150";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            bindings = <&mo &kp>, <&kp>;
        };

        lt_115: lt_115 {
            compatible = "zmk,behavior-hold-tap";
            label = "lt_115";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <115>;
            quick-tap-ms = <100>;
            bindings = <&mo &kp>, <&kp>;
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
