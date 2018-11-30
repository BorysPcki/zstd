/*
 * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under both the BSD-style license (found in the
 * LICENSE file in the root directory of this source tree) and the GPLv2 (found
 * in the COPYING file in the root directory of this source tree).
 * You may select, at your option, one of the above-listed licenses.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>

#define ZSTD_STATIC_LINKING_ONLY
#include <zstd.h>

typedef struct {
    ZSTD_cParameter param;
    unsigned value;
} param_value_t;

typedef struct {
    size_t size;
    param_value_t const* data;
} param_values_t;

/**
 * The config tells the compression method what options to use.
 */
typedef struct {
    const char* name;  /**< Identifies the config in the results table */
    /**
     * Optional arguments to pass to the CLI. If not set, CLI-based methods
     * will skip this config.
     */
    char const* cli_args;
    /**
     * Parameters to pass to the advanced API. If the advanced API isn't used,
     * the parameters will be derived from these.
     */
    param_values_t param_values;
} config_t;

#define CONFIG_NO_LEVEL (-ZSTD_TARGETLENGTH_MAX - 1)
/**
 * Returns the compression level specified by the config, or CONFIG_NO_LEVEL if
 * no level is specified. Note that 0 is a valid compression level, meaning
 * default.
 */
int config_get_level(config_t const* config);

/**
 * The NULL-terminated list of configs.
 */
extern config_t const* const* configs;

#endif