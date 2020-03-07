SOURCES += \
    ct_dcc_data.c \
    ct_dcc_debug_string.c \
    ct_dcc_leaf.c \
    ct_dcc_simple/simple_main.c \
    ct_dcc_simple/simple_path.c \
    ct_dcc_simple/simple_sublings.c \
    ct_dcc_simple/simple_table.c \
    ct_dcc_main.c \
    ct_dcc_node.c \
    main.c

HEADERS += \
    ct_dcc_data.h \
    ct_dcc_debug_string.h \
    ct_dcc_leaf.h \
    ct_dcc_simple/simple_main.h \
    ct_dcc_simple/simple_path.h \
    ct_dcc_simple/simple_sublings.h \
    ct_dcc_simple/simple_table.h \
    ct_dcc_main.h \
    ct_dcc_node.h

RESOURCES += \
    .gitignore \

CONFIG += \
    debug_and_release \
    console
