#pragma once

#include "esp_err.h"
#include "esp_netif_types.h"
#include "esp_wifi_types_generic.h"
#include "sdkconfig.h"
#include "wifi_creds.h"

#define WM_NETIF_DESC_STA "telepat_netif_sta"
#if CONFIG_WM_WIFI_SCAN_METHOD_FAST
#define WM_WIFI_SCAN_METHOD WIFI_FAST_SCAN
#elif CONFIG_WM_WIFI_SCAN_METHOD_ALL_CHANNEL
#define WM_WIFI_SCAN_METHOD WIFI_ALL_CHANNEL_SCAN
#endif

#if CONFIG_WM_WIFI_CONNECT_AP_BY_SIGNAL
#define WM_WIFI_CONNECT_AP_SORT_METHOD WIFI_CONNECT_AP_BY_SIGNAL
#elif CONFIG_WM_WIFI_CONNECT_AP_BY_SECURITY
#define WM_WIFI_CONNECT_AP_SORT_METHOD WIFI_CONNECT_AP_BY_SECURITY
#endif

#if CONFIG_WM_WIFI_AUTH_OPEN
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_OPEN
#elif CONFIG_WM_WIFI_AUTH_WEP
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WEP
#elif CONFIG_ESP_WIFI_AUTH_WPA_PSK
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_PSK
#elif CONFIG_WM_WIFI_AUTH_WPA2_PSK
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_PSK
#elif CONFIG_WM_WIFI_AUTH_WPA_WPA2_PSK
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_WPA2_PSK
#elif CONFIG_WM_WIFI_AUTH_WPA2_ENTERPRISE
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_ENTERPRISE
#elif CONFIG_WM_WIFI_AUTH_WPA3_PSK
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA3_PSK
#elif CONFIG_WM_WIFI_AUTH_WPA2_WPA3_PSK
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_WPA3_PSK
#elif CONFIG_WM_WIFI_AUTH_WAPI_PSK
#define WM_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WAPI_PSK
#endif

void wm_wifi_start(void);
void wm_wifi_stop(void);
esp_err_t wm_wifi_sta_do_connect(wifi_config_t wifi_config, bool wait);
esp_err_t wm_wifi_sta_do_disconnect(void);
bool wm_is_our_netif(const char *prefix, esp_netif_t *netif);
void wm_wifi_shutdown(void);
esp_err_t wm_wifi_connect(wifi_creds_t creds);
