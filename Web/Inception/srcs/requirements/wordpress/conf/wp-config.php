<?php

define( 'DB_NAME', 'thedatabase');
define( 'DB_USER', 'myuser');
define( 'DB_PASSWORD', 'abc');
define( 'DB_HOST', 'mariadb');
define( 'WP_HOME', 'https://mgauvrit.42.fr');
define( 'WP_SITEURL', 'https://mgauvrit.42.fr');
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

define( 'AUTH_KEY',         '' );
define( 'SECURE_AUTH_KEY',  '' );
define( 'LOGGED_IN_KEY',    '' );
define( 'NONCE_KEY',        '' );
define( 'AUTH_SALT',        '' );
define( 'SECURE_AUTH_SALT', '' );
define( 'LOGGED_IN_SALT',   '' );
define( 'NONCE_SALT',       '' );

$table_prefix = 'wp_';

define( 'WP_DEBUG', true );

if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';