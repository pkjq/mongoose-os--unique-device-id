#include <stdbool.h>
#include <string.h>

#include <mgos_sys_config.h>
#include <mgos_utils.h>
#include <mgos_ro_vars.h>


static void CorrectDeviceName()
{
    if (strcmp(mgos_sys_config_get_device_id(), "\%mac\%") == 0)
    {
        mgos_sys_config_set_device_id(mgos_sys_ro_vars_get_mac_address());
        mgos_sys_config_save(&mgos_sys_config, false, 0);
        mgos_system_restart_after(0);
    }
}


bool mgos_mongoose_os__unique_device_id_init(void)
{
    CorrectDeviceName();
    return true;
}
