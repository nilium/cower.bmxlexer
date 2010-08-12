### Intro

This is a simple lexer for the BlitzMax programming language (with additions- see *Additions* for notes on that).  It currently supplies a more or less functional C lexer that in turn is wrapped by BlitzMax.  The lexer is written by me as well.


### Installation

To install this module, simply clone it into BlitzMax/mod/cower.mod as bmxlexer.mod, like so:

    cd /Path/To/BlitzMax/mod
    mkdir cower.mod && cd cower.mod
    git clone git://github.com/nilium/cower.bmxlexer.git bmxlexer.mod

To build this, you will obviously need the usual tools (Xcode, MinGW, GCC, etc. depending on your platform).  If and when that's all set up, simply rebuild your modules either using `bmk makemods cower.bmxlexer` or in your preferred IDE.


### Additions

As mentioned in the intro, there have been some additions to the keywords other than those BlitzMax normally supports:

    Implements             ->          TOK_IMPLEMENTS_KW
    Protocol               ->          TOK_PROTOCOL_KW
    End\s?Protocol         ->          TOK_ENDPROTOCOL_KW
    Auto                   ->          TOK_AUTO_KW
    :=                     ->          TOK_ASSIGN_AUTO
    --                     ->          TOK_DOUBLEMINUS
    ++                     ->          TOK_DOUBLEPLUS
    ...                    ->          TOK_TRIPLEDOT

To disable support for these, modify your lexer.h and comment out the line defining `BMAX_USE_ADDITIONS`.  This will disable special treatment of those operators/keywords and they will again become identifiers and/or bizarre syntax errors.

Adding additional keywords is fairly simple, and any of those can be used as an example if need be (excepting triple-dot, which isn't considered an ordered pair or single).  That said, you should never remove a token from the `token_kind_t` enum unless you want to also remove its string equivalent.  Tokens that are unused will have no effect on the code, so it's better to leave them in place and simply add your own tokens onto the end (including string representations found in lexer.c).


### License

This source code is licensed under the extremely permissive zlib/libpng license:

    Copyright (c) 2010 Noel R. Cower

    This software is provided 'as-is', without any express or implied
    warranty. In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.
