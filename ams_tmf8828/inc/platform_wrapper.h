/*
*****************************************************************************
* Copyright by ams AG                                                       *
* All rights are reserved.                                                  *
*                                                                           *
* IMPORTANT - PLEASE READ CAREFULLY BEFORE COPYING, INSTALLING OR USING     *
* THE SOFTWARE.                                                             *
*                                                                           *
* THIS SOFTWARE IS PROVIDED FOR USE ONLY IN CONJUNCTION WITH AMS PRODUCTS.  *
* USE OF THE SOFTWARE IN CONJUNCTION WITH NON-AMS-PRODUCTS IS EXPLICITLY    *
* EXCLUDED.                                                                 *
*                                                                           *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT         *
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS         *
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,     *
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT          *
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     *
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.      *
*****************************************************************************
*/

#ifndef AMS_TMF8828_PLATFORM_WRAPPER_H_
#define AMS_TMF8828_PLATFORM_WRAPPER_H_

#include "tmf882x.h"
#include "tmf882x_mode_app_ioctl.h"
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "ams_rutdk2_i2c.h"

struct platform_ctx {
    char *i2cdev;
    uint32_t gpio_ce;
    uint32_t gpio_irq;
    uint32_t i2c_addr;
    uint32_t debug;
    uint32_t curr_num_measurements;
    uint32_t mode_8x8;
    struct tmf882x_tof *tof;
};

extern int32_t platform_wrapper_power_on();
extern void platform_wrapper_power_off();
extern int32_t platform_wrapper_init_device(struct platform_ctx *ctx, const uint8_t *hex_records, uint32_t size);
extern int32_t platform_wrapper_factory_calibration(struct platform_ctx *ctx, struct tmf882x_mode_app_calib *calib);
extern int32_t platform_wrapper_cfg_device(struct platform_ctx *ctx);
extern void platform_wrapper_start_measurements(struct platform_ctx *ctx, uint32_t num_measurements,
                                                const struct tmf882x_mode_app_calib *calib);
extern int32_t platform_wrapper_handle_msg(struct platform_ctx *ctx, struct tmf882x_msg *msg);
extern int32_t platform_wrapper_write_i2c_block(struct platform_ctx *ctx, uint8_t reg, const uint8_t *buf, uint32_t len);
extern int32_t platform_wrapper_read_i2c_block(struct platform_ctx *ctx, uint8_t reg, uint8_t *buf, uint32_t len);

#endif /* AMS_TMF8828_PLATFORM_WRAPPER_H_ */
