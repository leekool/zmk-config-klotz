/*
 * Copyright (c) 2021 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define LEE 0
#define NAV 1
#define NUM 2
#define FUN 3
#define BTC 4
#define CS2 5

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


#define COMBO(NAME, MS, BINDINGS, KEYPOS, LAYERS) \
combo_##NAME { \
    timeout-ms = <MS>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
    layers = <LAYERS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
        COMBO(delete, 90, &kp DEL, 30 31, 0 1 2 3 4 5)
        COMBO(fun_esc, 90, &lt FUN ESC, 32 33, 0 1 2 3 4 5)
        COMBO(grave, 90, &kp GRAVE, 8 9, 0 1 2 3 4 5)
        COMBO(semi, 90, &kp SEMI, 15 25, 0 1 2 3 4 5)
        COMBO(semi_thumb, 90, &kp SEMI, 15 33, 0 1 2 3 4 5)
        COMBO(dollar, 90, &kp DOLLAR, 5 15, 0 1 2 3 4 5)
        COMBO(equal, 90, &kp EQUAL, 6 16, 0 1 2 3 4 5)
        COMBO(escape, 40, &kp ESC, 0 1, 0 1 2 3 4 5)
        COMBO(lpar, 90, &lpar_shft, 4 14, 0 1 2 3 4)
        COMBO(rbkt, 90, &lbrc_shft, 14 24, 0 1 2 3 4)
        COMBO(f11, 90, &kp F11, 22 30, 3)
        COMBO(f12, 90, &kp F12, 23 30, 3)
        COMBO(const, 90, &macro_const, 1 3, 0 1 2 3 4)
        // COMBO(caps, 90, &caps_word, 20 29, 0 1 2 3 4 5)

        // CS2
        COMBO(cs_n1, 90, &kp N1, 4 14, 5)
        COMBO(cs_n2, 90, &kp N2, 14 24, 5)
        COMBO(cs_n5, 90, &kp N5, 24 30, 5)
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
            quick-tap-ms = <130>;
            bindings = <&mo &kp>, <&kp>;
        };

        lt_110: lt_110 {
            compatible = "zmk,behavior-hold-tap";
            label = "lt_110";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <110>;
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
