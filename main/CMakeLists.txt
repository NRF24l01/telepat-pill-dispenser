idf_component_register(SRCS "telepat-pill-dispenser.c"
                        PRIV_REQUIRES
                        nvs_flash esp_event esp_netif
                        global_manager 
                        wifi_manager 
                        pilld_models
                        pilld_common 
                        medsenger_http_requests 
                        buzzer 
                        display_error
                        button_controller 
                        cell_display_controller
                        captive_portal
                        cleaner
                        esp_driver_gpio
                        INCLUDE_DIRS ".")
