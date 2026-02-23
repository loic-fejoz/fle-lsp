module.exports = grammar({
    name: 'fle',

    extras: $ => [
        /\s/
    ],

    conflicts: $ => [
        [$.qso_line],
        [$.band_mode_line]
    ],

    rules: {
        source_file: $ => repeat(choice(
            $.comment,
            prec(2, $.header),
            prec(2, $.date_command),
            prec(2, $.day_command),
            prec(2, $.band_mode_line),
            prec(1, $.qso_line)
        )),

        // Simple comment without any lookaheads/assertions
        comment: $ => /#.*/,

        header: $ => seq(
            alias(choice(
                /[mM][yY][cC][aA][lL][lL]/,
                /[mM][yY][gG][rR][iI][dD]/,
                /[oO][pP][eE][rR][aA][tT][oO][rR]/,
                /[nN][iI][cC][kK][nN][aA][mM][eE]/,
                /[qQ][sS][lL][mM][sS][gG]/,
                /[mM][yY][wW][wW][fF][fF]/,
                /[mM][yY][sS][oO][tT][aA]/,
                /[mM][yY][pP][oO][tT][aA]/
            ), $.keyword),
            optional($.header_value)
        ),
        header_value: $ => /[^\n\r]+/,

        date_command: $ => seq(
            alias(/[dD][aA][tT][eE]/, $.keyword),
            $.date_value
        ),
        date_value: $ => /\d{4}-\d{2}-\d{2}/,

        day_command: $ => seq(
            alias(/[dD][aA][yY]/, $.keyword),
            $.day_value
        ),
        day_value: $ => /\++/,

        band_mode_line: $ => seq(
            choice($.band, $.mode),
            repeat(choice($.band, $.mode))
        ),

        band: $ => choice(
            /\d+(\.\d+)?([mM]|[cC][mM])/,
            /\d+\.\d+/
        ),
        mode: $ => choice(
            'CW', 'SSB', 'FM', 'AM', 'DIGI', 'FT8', 'FT4', 'PSK', 'RTTY',
            'VARAC', 'MFSK', 'DATA', 'JS8',
            'cw', 'ssb', 'fm', 'am', 'digi', 'ft8', 'ft4', 'psk', 'rtty',
            'varac', 'mfsk', 'data', 'js8'
        ),

        qso_line: $ => seq(
            optional($.time),
            $.callsign,
            repeat(choice($.rst, $.serial_sent, $.serial_rcvd)),
            repeat($.qso_extra)
        ),

        time: $ => /\d{2,4}/,
        callsign: $ => /[a-zA-Z0-9/]+/,
        rst: $ => /\d+/,
        serial_sent: $ => seq(',', /\d+/),
        serial_rcvd: $ => seq('.', /\d+/),

        qso_extra: $ => choice(
            $.grid,
            $.name,
            $.inline_comment,
            $.qsl_info,
            alias($.inline_hash_comment, $.comment)
        ),

        grid: $ => seq('#', /[a-zA-Z0-9]{2,8}/),
        name: $ => seq('@', /[^\s\n\r]+/),
        inline_comment: $ => seq('[', /[^\]]+/, ']'),
        qsl_info: $ => seq('<', /[^>]+/, '>'),
        inline_hash_comment: $ => seq('#', /[\t ]/, /.*/)
    }
}
);
