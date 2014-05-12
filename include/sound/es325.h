/*
 * es325.h  --  ES325 Soc Audio driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _ES325_H
#define _ES325_H

#include <sound/soc.h>

#define ES325_READ_VE_OFFSET		0x0804
#define ES325_READ_VE_WIDTH		4
#define ES325_WRITE_VE_OFFSET		0x0800
#define ES325_WRITE_VE_WIDTH		4

#define ES325_MCLK_DIV			0x0000
#define ES325_CLASSD_CLK_DIV		0x0001
#define ES325_CP_CLK_DIV		0x0002

#define ES325_BOOT_CMD			0x0001
#define ES325_BOOT_ACK			0x0101

#define ES325_SYNC_CMD			0x8000
#define ES325_SYNC_POLLING		0x0000
#define ES325_SYNC_INTR_ACITVE_LOW	0x0001
#define ES325_SYNC_INTR_ACITVE_HIGH	0x0002
#define ES325_SYNC_INTR_FALLING_EDGE	0x0003
#define ES325_SYNC_INTR_RISING_EDGE	0x0004
#define ES325_SYNC_ACK			0x00000000

#define ES325_RESET_CMD			0x8002
#define ES325_RESET_IMMED		0x0000
#define ES325_RESET_DELAYED		0x0001

#define ES325_SET_POWER_STATE		0x8010
#define ES325_SET_POWER_STATE_SLEEP	0x0001

/*
 * bit15 - reserved
 * bit[14:12] - access type
 * bit11 - commit = 0, staged = 1
 * bit[10:0] - psuedo address
 */
#define ES325_ACCESS_MASK	(7 << 12)
#define ES325_ALGO_ACCESS	(0 << 12)
#define ES325_DEV_ACCESS	(1 << 12)
#define ES325_CMD_ACCESS	(2 << 12)
#define ES325_OTHER_ACCESS	(3 << 12)

#define ES325_CMD_MASK		(1 << 11)
#define ES325_STAGED_CMD	(1 << 11)
#define ES325_COMMIT_CMD	(0 << 11)

#define ES325_ADDR_MASK		0x7ff

#define ES325_STAGED_MSG_BIT	(1 << 13)
/*
 * Device parameter command codes
 */
#define ES325_DEV_PARAM_OFFSET		0x2000
#define ES325_GET_DEV_PARAM		0x800b
#define ES325_SET_DEV_PARAMID		0x800c
#define ES325_SET_DEV_PARAM		0x800d

/*
 * Algoithm parameter command codes
 */
#define ES325_ALGO_PARAM_OFFSET		0x0000
#define ES325_GET_ALGO_PARAM		0x8016
#define ES325_SET_ALGO_PARAMID		0x8017
#define ES325_SET_ALGO_PARAM		0x8018

/*
 * addresses
 */
#define ES325_MIC_CONFIG		0x0000
#define ES325_MIC_CONFIG_STAGED	0x0800
#define ES325_AEC_MODE		0x0001
#define ES325_AEC_MODE_STAGED	0x0801
#define ES325_TX_AGC		0x0002
#define ES325_TX_AGC_STAGED	0x0802
#define ES325_TX_AGC_TARGET_LEVEL		0x0003
#define ES325_TX_AGC_TARGET_LEVEL_STAGED	0x0803
#define ES325_TX_AGC_NOISE_FLOOR		0x0004
#define ES325_TX_AGC_NOISE_FLOOR_STAGED	0x0804
#define ES325_TX_AGC_SNR_IMPROVEMENT		0x0005
#define ES325_TX_AGC_SNR_IMPROVEMENT_STAGED	0x0805
#define ES325_VEQ_ENABLE		0x0006
#define ES325_VEQ_ENABLE_STAGED	0x0806
#define ES325_RX_OUT_LIMITER_MAX_LEVEL		0x0007
#define ES325_RX_OUT_LIMITER_MAX_LEVEL_STAGED	0x0807
#define ES325_RX_NOISE_SUPPRESS		0x0008
#define ES325_RX_NOISE_SUPPRESS_STAGED	0x0808
#define ES325_RX_STS		0x0009
#define ES325_RX_STS_STAGED	0x0809
#define ES325_RX_STS_RATE		0x000A
#define ES325_RX_STS_RATE_STAGED	0x080A
#define ES325_AEC_SPEAKER_VOLUME		0x000B
#define ES325_AEC_SPEAKER_VOLUME_STAGED	0x080B
#define ES325_SIDETONE		0x000C
#define ES325_SIDETONE_STAGED	0x080C
#define ES325_SIDETONE_GAIN		0x000D
#define ES325_SIDETONE_GAIN_STAGED	0x080D
#define ES325_TX_COMFORT_NOISE		0x000E
#define ES325_TX_COMFORT_NOISE_STAGED	0x080E
#define ES325_TX_COMFORT_NOISE_LEVEL		0x000F
#define ES325_TX_COMFORT_NOISE_LEVEL_STAGED	0x080F
#define ES325_ALGORITHM_RESET		0x0010
#define ES325_ALGORITHM_RESET_STAGED	0x0810
#define ES325_RX_POST_EQ		0x0011
#define ES325_RX_POST_EQ_STAGED	0x0811
#define ES325_TX_POST_EQ		0x0012
#define ES325_TX_POST_EQ_STAGED	0x0812
#define ES325_AEC_CNG		0x0013
#define ES325_AEC_CNG_STAGED	0x0813
#define ES325_VEQ_NOISE_ESTIMATION_ADJUSTMENT		0x0014
#define ES325_VEQ_NOISE_ESTIMATION_ADJUSTMENT_STAGED	0x0814
#define ES325_TX_AGC_SLEW_RATE_UP		0x0015
#define ES325_TX_AGC_SLEW_RATE_UP_STAGED	0x0815
#define ES325_TX_AGC_SLEW_RATE_DOWN		0x0016
#define ES325_TX_AGC_SLEW_RATE_DOWN_STAGED	0x0816
#define ES325_RX_AGC		0x0017
#define ES325_RX_AGC_STAGED	0x0817
#define ES325_RX_AGC_TARGET_LEVEL		0x0018
#define ES325_RX_AGC_TARGET_LEVEL_STAGED	0x0818
#define ES325_RX_AGC_NOISE_FLOOR		0x0019
#define ES325_RX_AGC_NOISE_FLOOR_STAGED	0x0819
#define ES325_RX_AGC_SNR_IMPROVEMENT		0x001A
#define ES325_RX_AGC_SNR_IMPROVEMENT_STAGED	0x081A
#define ES325_RX_AGC_SLEW_RATE_UP		0x001B
#define ES325_RX_AGC_SLEW_RATE_UP_STAGED	0x081B
#define ES325_RX_AGC_SLEW_RATE_DOWN		0x001C
#define ES325_RX_AGC_SLEW_RATE_DOWN_STAGED	0x081C
#define ES325_AEC_CNG_GAIN		0x001D
#define ES325_AEC_CNG_GAIN_STAGED	0x081D
#define ES325_TX_MBC		0x001E
#define ES325_TX_MBC_STAGED	0x081E
#define ES325_RX_MBC		0x001F
#define ES325_RX_MBC_STAGED	0x081F
#define ES325_AEC_ESE		0x0020
#define ES325_AEC_ESE_STAGED	0x0820
#define ES325_TX_NS_ADAPTATION_SPEED		0x0021
#define ES325_TX_NS_ADAPTATION_SPEED_STAGED	0x0821
#define ES325_TX_SNR_ESTIMATE		0x0022
#define ES325_TX_SNR_ESTIMATE_STAGED	0x0822
#define ES325_VEQ_MAX_GAIN		0x0023
#define ES325_VEQ_MAX_GAIN_STAGED	0x0823
#define ES325_TX_AGC_GUARDBAND		0x0024
#define ES325_TX_AGC_GUARDBAND_STAGED	0x0824
#define ES325_RX_AGC_GUARDBAND		0x0025
#define ES325_RX_AGC_GUARDBAND_STAGED	0x0825
#define ES325_TX_OUT_LIMITER_MAX_LEVEL		0x0026
#define ES325_TX_OUT_LIMITER_MAX_LEVEL_STAGED	0x0826
#define ES325_TX_IN_LIMITER_MAX_LEVEL		0x0027
#define ES325_TX_IN_LIMITER_MAX_LEVEL_STAGED	0x0827
#define ES325_RX_NS_ADAPTATION_SPEED		0x0028
#define ES325_RX_NS_ADAPTATION_SPEED_STAGED	0x0828
#define ES325_AEC_VARIABLE_ECHO_REF_DELAY		0x0029
#define ES325_AEC_VARIABLE_ECHO_REF_DELAY_STAGED	0x0829
#define ES325_TX_NOISE_SUPPRESS_LEVEL		0x002A
#define ES325_TX_NOISE_SUPPRESS_LEVEL_STAGED	0x082A
#define ES325_RX_NOISE_SUPPRESS_LEVEL		0x002B
#define ES325_RX_NOISE_SUPPRESS_LEVEL_STAGED	0x082B
#define ES325_RX_CNG		0x002C
#define ES325_RX_CNG_STAGED	0x082C
#define ES325_RX_CNG_GAIN		0x002D
#define ES325_RX_CNG_GAIN_STAGED	0x082D
#define ES325_TX_AGC_MAX_GAIN		0x002E
#define ES325_TX_AGC_MAX_GAIN_STAGED	0x082E
#define ES325_RX_AGC_MAX_GAIN		0x002F
#define ES325_RX_AGC_MAX_GAIN_STAGED	0x082F
#define ES325_AVALON_API_VERSION_LO		0x0030
#define ES325_AVALON_API_VERSION_LO_STAGED	0x0830
#define ES325_AVALON_API_VERSION_HI		0x0031
#define ES325_AVALON_API_VERSION_HI_STAGED	0x0831
#define ES325_AVALON_AV_PROCESSOR		0x0032
#define ES325_AVALON_AV_PROCESSOR_STAGED	0x0832
#define ES325_AVALON_AV_CONFIG		0x0033
#define ES325_AVALON_AV_CONFIG_STAGED	0x0833
#define ES325_AVALON_EQ_PRESET		0x0034
#define ES325_AVALON_EQ_PRESET_STAGED	0x0834
#define ES325_AVALON_STEREO_WIDTH		0x0035
#define ES325_AVALON_STEREO_WIDTH_STAGED	0x0835
#define ES325_AVALON_AV_DIGITAL_OUT_GAIN		0x0036
#define ES325_AVALON_AV_DIGITAL_OUT_GAIN_STAGED	0x0836
#define ES325_AVALON_TDMBC		0x0037
#define ES325_AVALON_TDMBC_STAGED	0x0837
#define ES325_AVALON_AV_OUT_LIMIT		0x0038
#define ES325_AVALON_AV_OUT_LIMIT_STAGED	0x0838
#define ES325_AVALON_STEREO_WIDENING		0x0039
#define ES325_AVALON_STEREO_WIDENING_STAGED	0x0839
#define ES325_AVALON_STAT_NS		0x003A
#define ES325_AVALON_STAT_NS_STAGED	0x083A
#define ES325_AVALON_STAT_NS_SUPPRESS		0x003B
#define ES325_AVALON_STAT_NS_SUPPRESS_STAGED	0x083B
#define ES325_AVALON_STAT_NS_ADAP_SPEED		0x003C
#define ES325_AVALON_STAT_NS_ADAP_SPEED_STAGED	0x083C
#define ES325_AVALON_STAT_NS_MODE		0x003D
#define ES325_AVALON_STAT_NS_MODE_STAGED	0x083D
#define ES325_AVLALON_STAT_NS_MAX_NOISE_ENERGY		0x003E
#define ES325_AVLALON_STAT_NS_MAX_NOISE_ENERGY_STAGED	0x083E
#define ES325_AVALON_VBB		0x003F
#define ES325_AVALON_VBB_STAGED	0x083F
#define ES325_AVALON_VBB_STRENGTH		0x0040
#define ES325_AVALON_VBB_STRENGTH_STAGED	0x0840
#define ES325_AVALON_EQ_MODE		0x0041
#define ES325_AVALON_EQ_MODE_STAGED	0x0841
#define ES325_AVALON_EQ_GRAPHIC_BAND1_GAIN		0x0042
#define ES325_AVALON_EQ_GRAPHIC_BAND1_GAIN_STAGED	0x0842
#define ES325_AVALON_EQ_GRAPHIC_BAND2_GAIN		0x0043
#define ES325_AVALON_EQ_GRAPHIC_BAND2_GAIN_STAGED	0x0843
#define ES325_AVALON_EQ_GRAPHIC_BAND3_GAIN		0x0044
#define ES325_AVALON_EQ_GRAPHIC_BAND3_GAIN_STAGED	0x0844
#define ES325_AVALON_EQ_GRAPHIC_BAND4_GAIN		0x0045
#define ES325_AVALON_EQ_GRAPHIC_BAND4_GAIN_STAGED	0x0845
#define ES325_AVALON_EQ_GRAPHIC_BAND5_GAIN		0x0046
#define ES325_AVALON_EQ_GRAPHIC_BAND5_GAIN_STAGED	0x0846
#define ES325_AVALON_EQ_GRAPHIC_BAND6_GAIN		0x0047
#define ES325_AVALON_EQ_GRAPHIC_BAND6_GAIN_STAGED	0x0847
#define ES325_AVALON_EQ_GRAPHIC_BAND7_GAIN		0x0048
#define ES325_AVALON_EQ_GRAPHIC_BAND7_GAIN_STAGED	0x0848
#define ES325_AVALON_EQ_GRAPHIC_BAND8_GAIN		0x0049
#define ES325_AVALON_EQ_GRAPHIC_BAND8_GAIN_STAGED	0x0849
#define ES325_AVALON_EQ_GRAPHIC_BAND9_GAIN		0x004A
#define ES325_AVALON_EQ_GRAPHIC_BAND9_GAIN_STAGED	0x084A
#define ES325_AVALON_EQ_GRAPHIC_BAND10_GAIN		0x004B
#define ES325_AVALON_EQ_GRAPHIC_BAND10_GAIN_STAGED	0x084B
#define ES325_AVALON_TDDRC		0x004C
#define ES325_AVALON_TDDRC_STAGED	0x084C
#define ES325_AVALON_TDDRC_STRENGTH		0x004D
#define ES325_AVALON_TDDRC_STRENGTH_STAGED	0x084D
#define ES325_AVALON_LIMITER		0x004E
#define ES325_AVALON_LIMITER_STAGED	0x084E
#define ES325_AVALON_EQ		0x004F
#define ES325_AVALON_EQ_STAGED	0x084F
#define ES325_DIRAC		0x0050
#define ES325_DIRAC_STAGED	0x0850
#define ES325_DIRAC_OUT_HEADROOM_LIMITER		0x0051
#define ES325_DIRAC_OUT_HEADROOM_LIMITER_STAGED	0x0851
#define ES325_DIRAC_MODE		0x0052
#define ES325_DIRAC_MODE_STAGED	0x0852
#define ES325_DIRAC_IN_HEADROOM_LIMITER		0x0053
#define ES325_DIRAC_IN_HEADROOM_LIMITER_STAGED	0x0853
#define ES325_DIRAC_COMFORT_NOISE		0x0054
#define ES325_DIRAC_COMFORT_NOISE_STAGED	0x0854
#define ES325_DIRAC_COMFORT_NOISE_LEVEL		0x0055
#define ES325_DIRAC_COMFORT_NOISE_LEVEL_STAGED	0x0855
#define ES325_DIRAC_NARRATOR_VQOS		0x0056
#define ES325_DIRAC_NARRATOR_VQOS_STAGED	0x0856
#define ES325_DIRAC_NARRATOR_POSITION_SUPPRESS		0x0057
#define ES325_DIRAC_NARRATOR_POSITION_SUPPRESS_STAGED	0x0857
#define ES325_DIRAC_NARRATOR_AGC_OUT		0x0058
#define ES325_DIRAC_NARRATOR_AGC_OUT_STAGED	0x0858
#define ES325_DIRAC_NARRATOR_AGC_SPEECH_TARGET		0x0059
#define ES325_DIRAC_NARRATOR_AGC_SPEECH_TARGET_STAGED	0x0859
#define ES325_DIRAC_NARRATOR_AGC_SNR_IMPROVE		0x005A
#define ES325_DIRAC_NARRATOR_AGC_SNR_IMPROVE_STAGED	0x085A
#define ES325_DIRAC_NARRATOR_AGC_NOISE_FLOOR		0x005B
#define ES325_DIRAC_NARRATOR_AGC_NOISE_FLOOR_STAGED	0x085B
#define ES325_DIRAC_NARRATOR_AGC_MAX_GAIN		0x005C
#define ES325_DIRAC_NARRATOR_AGC_MAX_GAIN_STAGED	0x085C
#define ES325_DIRAC_NARRATOR_AGC_UP_RATE		0x005D
#define ES325_DIRAC_NARRATOR_AGC_UP_RATE_STAGED	0x085D
#define ES325_DIRAC_NARRATOR_AGC_DOWN_RATE		0x005E
#define ES325_DIRAC_NARRATOR_AGC_DOWN_RATE_STAGED	0x085E
#define ES325_DIRAC_NARRATOR_AGC_GUARDBAND		0x005F
#define ES325_DIRAC_NARRATOR_AGC_GUARDBAND_STAGED	0x085F
#define ES325_DIRAC_NARRATOR_POST_EQ_MODE		0x0060
#define ES325_DIRAC_NARRATOR_POST_EQ_MODE_STAGED	0x0860
#define ES325_DIRAC_NARRATOR_MBC_MODE		0x0061
#define ES325_DIRAC_NARRATOR_MBC_MODE_STAGED	0x0861
#define ES325_DIRAC_SCENE_BEAM_WIDTH		0x0062
#define ES325_DIRAC_SCENE_BEAM_WIDTH_STAGED	0x0862
#define ES325_DIRAC_SCENE_AGC_OUT		0x0063
#define ES325_DIRAC_SCENE_AGC_OUT_STAGED	0x0863
#define ES325_DIRAC_SCENE_AGC_SPEECH_TARGET		0x0064
#define ES325_DIRAC_SCENE_AGC_SPEECH_TARGET_STAGED	0x0864
#define ES325_DIRAC_SCENE_AGC_SNR_IMPROVE		0x0065
#define ES325_DIRAC_SCENE_AGC_SNR_IMPROVE_STAGED	0x0865
#define ES325_DIRAC_SCENE_AGC_NOISE_FLOOR		0x0066
#define ES325_DIRAC_SCENE_AGC_NOISE_FLOOR_STAGED	0x0866
#define ES325_DIRAC_SCENE_AGC_MAX_GAIN		0x0067
#define ES325_DIRAC_SCENE_AGC_MAX_GAIN_STAGED	0x0867
#define ES325_DIRAC_SCENE_AGC_UP_RATE		0x0068
#define ES325_DIRAC_SCENE_AGC_UP_RATE_STAGED	0x0868
#define ES325_DIRAC_SCENE_AGC_DOWN_RATE		0x0069
#define ES325_DIRAC_SCENE_AGC_DOWN_RATE_STAGED	0x0869
#define ES325_DIRAC_SCENE_AGC_GUARDBAND		0x006A
#define ES325_DIRAC_SCENE_AGC_GUARDBAND_STAGED	0x086A
#define ES325_DIRAC_SCENE_VQOS		0x006B
#define ES325_DIRAC_SCENE_VQOS_STAGED	0x086B
#define ES325_DIRAC_SCENE_POST_EQ_MODE		0x006C
#define ES325_DIRAC_SCENE_POST_EQ_MODE_STAGED	0x086C
#define ES325_DIRAC_SCENE_MBC_MODE		0x006D
#define ES325_DIRAC_SCENE_MBC_MODE_STAGED	0x086D
#define ES325_TONE_PARAM_API_VERSION_LO		0x006E
#define ES325_TONE_PARAM_API_VERSION_LO_STAGED	0x086E
#define ES325_TONE_PARAM_API_VERSION_HI		0x006F
#define ES325_TONE_PARAM_API_VERSION_HI_STAGED	0x086F
#define ES325_TONE_PARAM_ENABLE_BEEP_SYS		0x0070
#define ES325_TONE_PARAM_ENABLE_BEEP_SYS_STAGED	0x0870
#define ES325_TONE_PARAM_ENABLE_GEN_BEEP		0x0071
#define ES325_TONE_PARAM_ENABLE_GEN_BEEP_STAGED	0x0871
#define ES325_TONE_PARAM_GEN_BEEP_ON		0x0072
#define ES325_TONE_PARAM_GEN_BEEP_ON_STAGED	0x0872
#define ES325_TONE_PARAM_GEN_BEEP_FREQ1		0x0073
#define ES325_TONE_PARAM_GEN_BEEP_FREQ1_STAGED	0x0873
#define ES325_TONE_PARAM_GEN_BEEP_FREQ2		0x0074
#define ES325_TONE_PARAM_GEN_BEEP_FREQ2_STAGED	0x0874
#define ES325_TONE_PARAM_GEN_BEEP_PAN_LR		0x0075
#define ES325_TONE_PARAM_GEN_BEEP_PAN_LR_STAGED	0x0875
#define ES325_TONE_PARAM_GEN_BEEP_GAIN		0x0076
#define ES325_TONE_PARAM_GEN_BEEP_GAIN_STAGED	0x0876
#define ES325_DEREVERB_ENABLE		0x0077
#define ES325_DEREVERB_ENABLE_STAGED	0x0877
#define ES325_DEREVERB_GAIN		0x0078
#define ES325_DEREVERB_GAIN_STAGED	0x0878
#define ES325_BWE_ENABLE		0x0079
#define ES325_BWE_ENABLE_STAGED		0x0879
#define ES325_BWE_HIGH_BAND_GAIN	0x007a
#define ES325_BWE_HIGH_BAND_GAIN_STAGED	0x087a
#define ES325_BWE_MAX_SNR		0x007b
#define ES325_BWE_MAX_SNR_STAGED	0x087b
#define ES325_BWE_POST_EQ_ENABLE	0x007c
#define ES325_BWE_POST_EQ_ENABLE_STAGED	0x087c
#define ES325_POS_SUPP_TRADEOFF		0x007d
#define ES325_POS_SUPP_TRADEOFF_STAGED	0x087d
#define ES325_TX_INTR_LEVEL		0x007e
#define ES325_TX_INTR_LEVEL_STAGED	0x087e
#define ES325_PORTA_WORD_LEN		0x1000
#define ES325_PORTA_WORD_LEN_STAGED	0x1800
#define ES325_PORTA_TDM_SLOTS_PER_FRAME		0x1001
#define ES325_PORTA_TDM_SLOTS_PER_FRAME_STAGED	0x1801
#define ES325_PORTA_TX_DELAY_FROM_FS		0x1002
#define ES325_PORTA_TX_DELAY_FROM_FS_STAGED	0x1802
#define ES325_PORTA_RX_DELAY_FROM_FS		0x1003
#define ES325_PORTA_RX_DELAY_FROM_FS_STAGED	0x1803
#define ES325_PORTA_LATCH_EDGE		0x1004
#define ES325_PORTA_LATCH_EDGE_STAGED	0x1804
#define ES325_PORTA_ENDIAN		0x1005
#define ES325_PORTA_ENDIAN_STAGED	0x1805
#define ES325_PORTA_TRISTATE		0x1006
#define ES325_PORTA_TRISTATE_STAGED	0x1806
#define ES325_PORTA_AUDIO_PORT_MODE		0x1007
#define ES325_PORTA_AUDIO_PORT_MODE_STAGED	0x1807
#define ES325_PORTA_TDM_ENABLED		0x1008
#define ES325_PORTA_TDM_ENABLED_STAGED	0x1808
#define ES325_PORTA_CLOCK_CONTROL		0x1009
#define ES325_PORTA_CLOCK_CONTROL_STAGED	0x1809
#define ES325_PORTA_DATA_JUSTIFICATION		0x100A
#define ES325_PORTA_DATA_JUSTIFICATION_STAGED	0x180A
#define ES325_PORTA_FS_DURATION		0x100B
#define ES325_PORTA_FS_DURATION_STAGED	0x180B
#define ES325_PORTB_WORD_LEN		0x100C
#define ES325_PORTB_WORD_LEN_STAGED	0x180C
#define ES325_PORTB_TDM_SLOTS_PER_FRAME		0x100D
#define ES325_PORTB_TDM_SLOTS_PER_FRAME_STAGED	0x180D
#define ES325_PORTB_TX_DELAY_FROM_FS		0x100E
#define ES325_PORTB_TX_DELAY_FROM_FS_STAGED	0x180E
#define ES325_PORTB_RX_DELAY_FROM_FS		0x100F
#define ES325_PORTB_RX_DELAY_FROM_FS_STAGED	0x180F
#define ES325_PORTB_LATCH_EDGE		0x1010
#define ES325_PORTB_LATCH_EDGE_STAGED	0x1810
#define ES325_PORTB_ENDIAN		0x1011
#define ES325_PORTB_ENDIAN_STAGED	0x1811
#define ES325_PORTB_TRISTATE		0x1012
#define ES325_PORTB_TRISTATE_STAGED	0x1812
#define ES325_PORTB_AUDIO_PORT_MODE		0x1013
#define ES325_PORTB_AUDIO_PORT_MODE_STAGED	0x1813
#define ES325_PORTB_TDM_ENABLED		0x1014
#define ES325_PORTB_TDM_ENABLED_STAGED	0x1814
#define ES325_PORTB_CLOCK_CONTROL		0x1015
#define ES325_PORTB_CLOCK_CONTROL_STAGED	0x1815
#define ES325_PORTB_DATA_JUSTIFICATION		0x1016
#define ES325_PORTB_DATA_JUSTIFICATION_STAGED	0x1816
#define ES325_PORTB_FS_DURATION		0x1017
#define ES325_PORTB_FS_DURATION_STAGED	0x1817
#define ES325_PORTC_WORD_LEN		0x1018
#define ES325_PORTC_WORD_LEN_STAGED	0x1818
#define ES325_PORTC_TDM_SLOTS_PER_FRAME		0x1019
#define ES325_PORTC_TDM_SLOTS_PER_FRAME_STAGED	0x1819
#define ES325_PORTC_TX_DELAY_FROM_FS		0x101A
#define ES325_PORTC_TX_DELAY_FROM_FS_STAGED	0x181A
#define ES325_PORTC_RX_DELAY_FROM_FS		0x101B
#define ES325_PORTC_RX_DELAY_FROM_FS_STAGED	0x181B
#define ES325_PORTC_LATCH_EDGE		0x101C
#define ES325_PORTC_LATCH_EDGE_STAGED	0x181C
#define ES325_PORTC_ENDIAN		0x101D
#define ES325_PORTC_ENDIAN_STAGED	0x181D
#define ES325_PORTC_TRISTATE		0x101E
#define ES325_PORTC_TRISTATE_STAGED	0x181E
#define ES325_PORTC_AUDIO_PORT_MODE		0x101F
#define ES325_PORTC_AUDIO_PORT_MODE_STAGED	0x181F
#define ES325_PORTC_TDM_ENABLED		0x1020
#define ES325_PORTC_TDM_ENABLED_STAGED	0x1820
#define ES325_PORTC_CLOCK_CONTROL		0x1021
#define ES325_PORTC_CLOCK_CONTROL_STAGED	0x1821
#define ES325_PORTC_DATA_JUSTIFICATION		0x1022
#define ES325_PORTC_DATA_JUSTIFICATION_STAGED	0x1822
#define ES325_PORTC_FS_DURATION		0x1023
#define ES325_PORTC_FS_DURATION_STAGED	0x1823
#define ES325_PORTD_WORD_LEN		0x1024
#define ES325_PORTD_WORD_LEN_STAGED	0x1824
#define ES325_PORTD_TDM_SLOTS_PER_FRAME		0x1025
#define ES325_PORTD_TDM_SLOTS_PER_FRAME_STAGED	0x1825
#define ES325_PORTD_TX_DELAY_FROM_FS		0x1026
#define ES325_PORTD_TX_DELAY_FROM_FS_STAGED	0x1826
#define ES325_PORTD_RX_DELAY_FROM_FS		0x1027
#define ES325_PORTD_RX_DELAY_FROM_FS_STAGED	0x1827
#define ES325_PORTD_LATCH_EDGE		0x1028
#define ES325_PORTD_LATCH_EDGE_STAGED	0x1828
#define ES325_PORTD_ENDIAN		0x1029
#define ES325_PORTD_ENDIAN_STAGED	0x1829
#define ES325_PORTD_TRISTATE		0x102A
#define ES325_PORTD_TRISTATE_STAGED	0x182A
#define ES325_PORTD_AUDIO_PORT_MODE		0x102B
#define ES325_PORTD_AUDIO_PORT_MODE_STAGED	0x182B
#define ES325_PORTD_TDM_ENABLED		0x102C
#define ES325_PORTD_TDM_ENABLED_STAGED	0x182C
#define ES325_PORTD_CLOCK_CONTROL		0x102D
#define ES325_PORTD_CLOCK_CONTROL_STAGED	0x182D
#define ES325_PORTD_DATA_JUSTIFICATION		0x102E
#define ES325_PORTD_DATA_JUSTIFICATION_STAGED	0x182E
#define ES325_PORTD_FS_DURATION		0x102F
#define ES325_PORTD_FS_DURATION_STAGED	0x182F
#define ES325_SLIMBUS_LINK_MULTI_CHANNEL		0x1030
#define ES325_SLIMBUS_LINK_MULTI_CHANNEL_STAGED	0x1830
#define ES325_POWER_STATE		0x2000
#define ES325_POWER_STATE_STAGED	0x2800
#define ES325_STREAMING		0x2001
#define ES325_STREAMING_STAGED	0x2801
#define ES325_FE_STREAMING		0x2002
#define ES325_FE_STREAMING_STAGED	0x2802
#define ES325_PRESET		0x2003
#define ES325_PRESET_STAGED	0x2803
#define ES325_ALGO_STATS		0x2004
#define ES325_ALGO_STATS_STAGED	0x2804
#define ES325_ALGO_PROCESSING		0x2005
#define ES325_ALGO_PROCESSING_STAGED	0x2805
#define ES325_ALGO_SAMPLE_RATE		0x2006
#define ES325_ALGO_SAMPLE_RATE_STAGED	0x2806
#define ES325_SMOOTH_RATE		0x2007
#define ES325_SMOOTH_RATE_STAGED	0x2807
#define ES325_CHANGE_STATUS		0x2008
#define ES325_CHANGE_STATUS_STAGED	0x2808
#define ES325_DIGITAL_PASS_THROUGH		0x2009
#define ES325_DIGITAL_PASS_THROUGH_STAGED	0x2809
#define ES325_DATA_PATH		0x200A
#define ES325_DATA_PATH_STAGED	0x280A
#define ES325_ALGORITHM		0x200B
#define ES325_ALGORITHM_STAGED	0x280B
#define ES325_MIX_SAMPLE_RATE		0x200C
#define ES325_MIX_SAMPLE_RATE_STAGED	0x280C
#define ES325_SIGNAL_RMS_PORTA_DIN_LEFT		0x200D
#define ES325_SIGNAL_RMS_PORTA_DIN_LEFT_STAGED	0x280D
#define ES325_SIGNAL_RMS_PORTA_DIN_RIGHT		0x200E
#define ES325_SIGNAL_RMS_PORTA_DIN_RIGHT_STAGED	0x280E
#define ES325_SIGNAL_RMS_PORTA_DOUT_LEFT		0x200F
#define ES325_SIGNAL_RMS_PORTA_DOUT_LEFT_STAGED	0x280F
#define ES325_SIGNAL_RMS_PORTA_DOUT_RIGHT		0x2010
#define ES325_SIGNAL_RMS_PORTA_DOUT_RIGHT_STAGED	0x2810
#define ES325_SIGNAL_RMS_PORTB_DIN_LEFT		0x2011
#define ES325_SIGNAL_RMS_PORTB_DIN_LEFT_STAGED	0x2811
#define ES325_SIGNAL_RMS_PORTB_DIN_RIGHT		0x2012
#define ES325_SIGNAL_RMS_PORTB_DIN_RIGHT_STAGED	0x2812
#define ES325_SIGNAL_RMS_PORTB_DOUT_LEFT		0x2013
#define ES325_SIGNAL_RMS_PORTB_DOUT_LEFT_STAGED	0x2813
#define ES325_SIGNAL_RMS_PORTB_DOUT_RIGHT		0x2014
#define ES325_SIGNAL_RMS_PORTB_DOUT_RIGHT_STAGED	0x2814
#define ES325_SIGNAL_RMS_PORTC_DIN_LEFT		0x2015
#define ES325_SIGNAL_RMS_PORTC_DIN_LEFT_STAGED	0x2815
#define ES325_SIGNAL_RMS_PORTC_DIN_RIGHT		0x2016
#define ES325_SIGNAL_RMS_PORTC_DIN_RIGHT_STAGED	0x2816
#define ES325_SIGNAL_RMS_PORTC_DOUT_LEFT		0x2017
#define ES325_SIGNAL_RMS_PORTC_DOUT_LEFT_STAGED	0x2817
#define ES325_SIGNAL_RMS_PORTC_DOUT_RIGHT		0x2018
#define ES325_SIGNAL_RMS_PORTC_DOUT_RIGHT_STAGED	0x2818
#define ES325_SIGNAL_RMS_PORTD_DIN_LEFT		0x2019
#define ES325_SIGNAL_RMS_PORTD_DIN_LEFT_STAGED	0x2819
#define ES325_SIGNAL_RMS_PORTD_DIN_RIGHT		0x201A
#define ES325_SIGNAL_RMS_PORTD_DIN_RIGHT_STAGED	0x281A
#define ES325_SIGNAL_RMS_PORTD_DOUT_LEFT		0x201B
#define ES325_SIGNAL_RMS_PORTD_DOUT_LEFT_STAGED	0x281B
#define ES325_SIGNAL_RMS_PORTD_DOUT_RIGHT		0x201C
#define ES325_SIGNAL_RMS_PORTD_DOUT_RIGHT_STAGED	0x281C
#define ES325_SIGNAL_PEAK_PORTA_DIN_LEFT		0x201D
#define ES325_SIGNAL_PEAK_PORTA_DIN_LEFT_STAGED	0x281D
#define ES325_SIGNAL_PEAK_PORTA_DIN_RIGHT		0x201E
#define ES325_SIGNAL_PEAK_PORTA_DIN_RIGHT_STAGED	0x281E
#define ES325_SIGNAL_PEAK_PORTA_DOUT_LEFT		0x201F
#define ES325_SIGNAL_PEAK_PORTA_DOUT_LEFT_STAGED	0x281F
#define ES325_SIGNAL_PEAK_PORTA_DOUT_RIGHT		0x2020
#define ES325_SIGNAL_PEAK_PORTA_DOUT_RIGHT_STAGED	0x2820
#define ES325_SIGNAL_PEAK_PORTB_DIN_LEFT		0x2021
#define ES325_SIGNAL_PEAK_PORTB_DIN_LEFT_STAGED	0x2821
#define ES325_SIGNAL_PEAK_PORTB_DIN_RIGHT		0x2022
#define ES325_SIGNAL_PEAK_PORTB_DIN_RIGHT_STAGED	0x2822
#define ES325_SIGNAL_PEAK_PORTB_DOUT_LEFT		0x2023
#define ES325_SIGNAL_PEAK_PORTB_DOUT_LEFT_STAGED	0x2823
#define ES325_SIGNAL_PEAK_PORTB_DOUT_RIGHT		0x2024
#define ES325_SIGNAL_PEAK_PORTB_DOUT_RIGHT_STAGED	0x2824
#define ES325_SIGNAL_PEAK_PORTC_DIN_LEFT		0x2025
#define ES325_SIGNAL_PEAK_PORTC_DIN_LEFT_STAGED	0x2825
#define ES325_SIGNAL_PEAK_PORTC_DIN_RIGHT		0x2026
#define ES325_SIGNAL_PEAK_PORTC_DIN_RIGHT_STAGED	0x2826
#define ES325_SIGNAL_PEAK_PORTC_DOUT_LEFT		0x2027
#define ES325_SIGNAL_PEAK_PORTC_DOUT_LEFT_STAGED	0x2827
#define ES325_SIGNAL_PEAK_PORTC_DOUT_RIGHT		0x2028
#define ES325_SIGNAL_PEAK_PORTC_DOUT_RIGHT_STAGED	0x2828
#define ES325_SIGNAL_PEAK_PORTD_DIN_LEFT		0x2029
#define ES325_SIGNAL_PEAK_PORTD_DIN_LEFT_STAGED	0x2829
#define ES325_SIGNAL_PEAK_PORTD_DIN_RIGHT		0x202A
#define ES325_SIGNAL_PEAK_PORTD_DIN_RIGHT_STAGED	0x282A
#define ES325_SIGNAL_PEAK_PORTD_DOUT_LEFT		0x202B
#define ES325_SIGNAL_PEAK_PORTD_DOUT_LEFT_STAGED	0x282B
#define ES325_SIGNAL_PEAK_PORTD_DOUT_RIGHT		0x202C
#define ES325_SIGNAL_PEAK_PORTD_DOUT_RIGHT_STAGED	0x282C
#define ES325_DIGITAL_GAIN_PRIMARY		0x202D
#define ES325_DIGITAL_GAIN_PRIMARY_STAGED	0x282D
#define ES325_DIGITAL_GAIN_SECONDARY		0x202E
#define ES325_DIGITAL_GAIN_SECONDARY_STAGED	0x282E
#define ES325_DIGITAL_GAIN_TERTIARY		0x202F
#define ES325_DIGITAL_GAIN_TERTIARY_STAGED	0x282F
#define ES325_DIGITAL_GAIN_QUAD		0x2030
#define ES325_DIGITAL_GAIN_QUAD_STAGED	0x2830
#define ES325_DIGITAL_GAIN_FEIN		0x2031
#define ES325_DIGITAL_GAIN_FEIN_STAGED	0x2831
#define ES325_DIGITAL_GAIN_AUDIN1		0x2032
#define ES325_DIGITAL_GAIN_AUDIN1_STAGED	0x2832
#define ES325_DIGITAL_GAIN_AUDIN2		0x2033
#define ES325_DIGITAL_GAIN_AUDIN2_STAGED	0x2833
#define ES325_DIGITAL_GAIN_AUDIN3		0x2034
#define ES325_DIGITAL_GAIN_AUDIN3_STAGED	0x2834
#define ES325_DIGITAL_GAIN_AUDIN4		0x2035
#define ES325_DIGITAL_GAIN_AUDIN4_STAGED	0x2835
#define ES325_DIGITAL_GAIN_UITONE1		0x2036
#define ES325_DIGITAL_GAIN_UITONE1_STAGED	0x2836
#define ES325_DIGITAL_GAIN_UITONE2		0x2037
#define ES325_DIGITAL_GAIN_UITONE2_STAGED	0x2837
#define ES325_DIGITAL_GAIN_CSOUT		0x2038
#define ES325_DIGITAL_GAIN_CSOUT_STAGED	0x2838
#define ES325_DIGITAL_GAIN_FEOUT1		0x2039
#define ES325_DIGITAL_GAIN_FEOUT1_STAGED	0x2839
#define ES325_DIGITAL_GAIN_FEOUT2		0x203A
#define ES325_DIGITAL_GAIN_FEOUT2_STAGED	0x283A
#define ES325_DIGITAL_GAIN_AUDOUT1		0x203B
#define ES325_DIGITAL_GAIN_AUDOUT1_STAGED	0x283B
#define ES325_DIGITAL_GAIN_AUDOUT2		0x203C
#define ES325_DIGITAL_GAIN_AUDOUT2_STAGED	0x283C
#define ES325_DIGITAL_GAIN_AUDOUT3		0x203D
#define ES325_DIGITAL_GAIN_AUDOUT3_STAGED	0x283D
#define ES325_DIGITAL_GAIN_AUDOUT4		0x203E
#define ES325_DIGITAL_GAIN_AUDOUT4_STAGED	0x283E
#define ES325_PORTA_TIMING		0x203F
#define ES325_PORTA_TIMING_STAGED	0x283F
#define ES325_PORTB_TIMING		0x2040
#define ES325_PORTB_TIMING_STAGED	0x2840
#define ES325_PORTC_TIMING		0x2041
#define ES325_PORTC_TIMING_STAGED	0x2841
#define ES325_PORTD_TIMING		0x2042
#define ES325_PORTD_TIMING_STAGED	0x2842
#define ES325_PRIMARY_PATH_MUX		0x2043
#define ES325_PRIMARY_PATH_MUX_STAGED	0x2843
#define ES325_SECONDARY_PATH_MUX		0x2044
#define ES325_SECONDARY_PATH_MUX_STAGED	0x2844
#define ES325_TERTIARY_PATH_MUX		0x2045
#define ES325_TERTIARY_PATH_MUX_STAGED	0x2845
#define ES325_QUAD_PATH_MUX		0x2046
#define ES325_QUAD_PATH_MUX_STAGED	0x2846
#define ES325_FEIN_PATH_MUX		0x2047
#define ES325_FEIN_PATH_MUX_STAGED	0x2847
#define ES325_AUDIN1_PATH_MUX		0x2048
#define ES325_AUDIN1_PATH_MUX_STAGED	0x2848
#define ES325_AUDIN2_PATH_MUX		0x2049
#define ES325_AUDIN2_PATH_MUX_STAGED	0x2849
#define ES325_AUDIN3_PATH_MUX		0x204A
#define ES325_AUDIN3_PATH_MUX_STAGED	0x284A
#define ES325_AUDIN4_PATH_MUX		0x204B
#define ES325_AUDIN4_PATH_MUX_STAGED	0x284B
#define ES325_UITONE1_PATH_MUX		0x204C
#define ES325_UITONE1_PATH_MUX_STAGED	0x284C
#define ES325_UITONE2_PATH_MUX		0x204D
#define ES325_UITONE2_PATH_MUX_STAGED	0x284D
#define ES325_PCM0_0_PATH_MUX		0x204E
#define ES325_PCM0_0_PATH_MUX_STAGED	0x284E
#define ES325_PCM0_1_PATH_MUX		0x204F
#define ES325_PCM0_1_PATH_MUX_STAGED	0x284F
#define ES325_PCM0_2_PATH_MUX		0x2050
#define ES325_PCM0_2_PATH_MUX_STAGED	0x2850
#define ES325_PCM0_3_PATH_MUX		0x2051
#define ES325_PCM0_3_PATH_MUX_STAGED	0x2851
#define ES325_PCM0_4_PATH_MUX		0x2052
#define ES325_PCM0_4_PATH_MUX_STAGED	0x2852
#define ES325_PCM0_5_PATH_MUX		0x2053
#define ES325_PCM0_5_PATH_MUX_STAGED	0x2853
#define ES325_PCM0_6_PATH_MUX		0x2054
#define ES325_PCM0_6_PATH_MUX_STAGED	0x2854
#define ES325_PCM0_7_PATH_MUX		0x2055
#define ES325_PCM0_7_PATH_MUX_STAGED	0x2855
#define ES325_PCM0_8_PATH_MUX		0x2056
#define ES325_PCM0_8_PATH_MUX_STAGED	0x2856
#define ES325_PCM0_9_PATH_MUX		0x2057
#define ES325_PCM0_9_PATH_MUX_STAGED	0x2857
#define ES325_PCM0_10_PATH_MUX		0x2058
#define ES325_PCM0_10_PATH_MUX_STAGED	0x2858
#define ES325_PCM0_11_PATH_MUX		0x2059
#define ES325_PCM0_11_PATH_MUX_STAGED	0x2859
#define ES325_PCM0_12_PATH_MUX		0x205A
#define ES325_PCM0_12_PATH_MUX_STAGED	0x285A
#define ES325_PCM0_13_PATH_MUX		0x205B
#define ES325_PCM0_13_PATH_MUX_STAGED	0x285B
#define ES325_PCM0_14_PATH_MUX		0x205C
#define ES325_PCM0_14_PATH_MUX_STAGED	0x285C
#define ES325_PCM0_15_PATH_MUX		0x205D
#define ES325_PCM0_15_PATH_MUX_STAGED	0x285D
#define ES325_PCM0_16_PATH_MUX		0x205E
#define ES325_PCM0_16_PATH_MUX_STAGED	0x285E
#define ES325_PCM0_17_PATH_MUX		0x205F
#define ES325_PCM0_17_PATH_MUX_STAGED	0x285F
#define ES325_PCM0_18_PATH_MUX		0x2060
#define ES325_PCM0_18_PATH_MUX_STAGED	0x2860
#define ES325_PCM0_19_PATH_MUX		0x2061
#define ES325_PCM0_19_PATH_MUX_STAGED	0x2861
#define ES325_PCM0_20_PATH_MUX		0x2062
#define ES325_PCM0_20_PATH_MUX_STAGED	0x2862
#define ES325_PCM0_21_PATH_MUX		0x2063
#define ES325_PCM0_21_PATH_MUX_STAGED	0x2863
#define ES325_PCM0_22_PATH_MUX		0x2064
#define ES325_PCM0_22_PATH_MUX_STAGED	0x2864
#define ES325_PCM0_23_PATH_MUX		0x2065
#define ES325_PCM0_23_PATH_MUX_STAGED	0x2865
#define ES325_PCM0_24_PATH_MUX		0x2066
#define ES325_PCM0_24_PATH_MUX_STAGED	0x2866
#define ES325_PCM0_25_PATH_MUX		0x2067
#define ES325_PCM0_25_PATH_MUX_STAGED	0x2867
#define ES325_PCM0_26_PATH_MUX		0x2068
#define ES325_PCM0_26_PATH_MUX_STAGED	0x2868
#define ES325_PCM0_27_PATH_MUX		0x2069
#define ES325_PCM0_27_PATH_MUX_STAGED	0x2869
#define ES325_PCM0_28_PATH_MUX		0x206A
#define ES325_PCM0_28_PATH_MUX_STAGED	0x286A
#define ES325_PCM0_29_PATH_MUX		0x206B
#define ES325_PCM0_29_PATH_MUX_STAGED	0x286B
#define ES325_PCM0_30_PATH_MUX		0x206C
#define ES325_PCM0_30_PATH_MUX_STAGED	0x286C
#define ES325_PCM0_31_PATH_MUX		0x206D
#define ES325_PCM0_31_PATH_MUX_STAGED	0x286D
#define ES325_PCM1_0_PATH_MUX		0x206E
#define ES325_PCM1_0_PATH_MUX_STAGED	0x286E
#define ES325_PCM1_1_PATH_MUX		0x206F
#define ES325_PCM1_1_PATH_MUX_STAGED	0x286F
#define ES325_PCM1_2_PATH_MUX		0x2070
#define ES325_PCM1_2_PATH_MUX_STAGED	0x2870
#define ES325_PCM1_3_PATH_MUX		0x2071
#define ES325_PCM1_3_PATH_MUX_STAGED	0x2871
#define ES325_PCM1_4_PATH_MUX		0x2072
#define ES325_PCM1_4_PATH_MUX_STAGED	0x2872
#define ES325_PCM1_5_PATH_MUX		0x2073
#define ES325_PCM1_5_PATH_MUX_STAGED	0x2873
#define ES325_PCM1_6_PATH_MUX		0x2074
#define ES325_PCM1_6_PATH_MUX_STAGED	0x2874
#define ES325_PCM1_7_PATH_MUX		0x2075
#define ES325_PCM1_7_PATH_MUX_STAGED	0x2875
#define ES325_PCM1_8_PATH_MUX		0x2076
#define ES325_PCM1_8_PATH_MUX_STAGED	0x2876
#define ES325_PCM1_9_PATH_MUX		0x2077
#define ES325_PCM1_9_PATH_MUX_STAGED	0x2877
#define ES325_PCM1_10_PATH_MUX		0x2078
#define ES325_PCM1_10_PATH_MUX_STAGED	0x2878
#define ES325_PCM1_11_PATH_MUX		0x2079
#define ES325_PCM1_11_PATH_MUX_STAGED	0x2879
#define ES325_PCM1_12_PATH_MUX		0x207A
#define ES325_PCM1_12_PATH_MUX_STAGED	0x287A
#define ES325_PCM1_13_PATH_MUX		0x207B
#define ES325_PCM1_13_PATH_MUX_STAGED	0x287B
#define ES325_PCM1_14_PATH_MUX		0x207C
#define ES325_PCM1_14_PATH_MUX_STAGED	0x287C
#define ES325_PCM1_15_PATH_MUX		0x207D
#define ES325_PCM1_15_PATH_MUX_STAGED	0x287D
#define ES325_PCM1_16_PATH_MUX		0x207E
#define ES325_PCM1_16_PATH_MUX_STAGED	0x287E
#define ES325_PCM1_17_PATH_MUX		0x207F
#define ES325_PCM1_17_PATH_MUX_STAGED	0x287F
#define ES325_PCM1_18_PATH_MUX		0x2080
#define ES325_PCM1_18_PATH_MUX_STAGED	0x2880
#define ES325_PCM1_19_PATH_MUX		0x2081
#define ES325_PCM1_19_PATH_MUX_STAGED	0x2881
#define ES325_PCM1_20_PATH_MUX		0x2082
#define ES325_PCM1_20_PATH_MUX_STAGED	0x2882
#define ES325_PCM1_21_PATH_MUX		0x2083
#define ES325_PCM1_21_PATH_MUX_STAGED	0x2883
#define ES325_PCM1_22_PATH_MUX		0x2084
#define ES325_PCM1_22_PATH_MUX_STAGED	0x2884
#define ES325_PCM1_23_PATH_MUX		0x2085
#define ES325_PCM1_23_PATH_MUX_STAGED	0x2885
#define ES325_PCM1_24_PATH_MUX		0x2086
#define ES325_PCM1_24_PATH_MUX_STAGED	0x2886
#define ES325_PCM1_25_PATH_MUX		0x2087
#define ES325_PCM1_25_PATH_MUX_STAGED	0x2887
#define ES325_PCM1_26_PATH_MUX		0x2088
#define ES325_PCM1_26_PATH_MUX_STAGED	0x2888
#define ES325_PCM1_27_PATH_MUX		0x2089
#define ES325_PCM1_27_PATH_MUX_STAGED	0x2889
#define ES325_PCM1_28_PATH_MUX		0x208A
#define ES325_PCM1_28_PATH_MUX_STAGED	0x288A
#define ES325_PCM1_29_PATH_MUX		0x208B
#define ES325_PCM1_29_PATH_MUX_STAGED	0x288B
#define ES325_PCM1_30_PATH_MUX		0x208C
#define ES325_PCM1_30_PATH_MUX_STAGED	0x288C
#define ES325_PCM1_31_PATH_MUX		0x208D
#define ES325_PCM1_31_PATH_MUX_STAGED	0x288D
#define ES325_PCM2_0_PATH_MUX		0x208E
#define ES325_PCM2_0_PATH_MUX_STAGED	0x288E
#define ES325_PCM2_1_PATH_MUX		0x208F
#define ES325_PCM2_1_PATH_MUX_STAGED	0x288F
#define ES325_PCM2_2_PATH_MUX		0x2090
#define ES325_PCM2_2_PATH_MUX_STAGED	0x2890
#define ES325_PCM2_3_PATH_MUX		0x2091
#define ES325_PCM2_3_PATH_MUX_STAGED	0x2891
#define ES325_PCM2_4_PATH_MUX		0x2092
#define ES325_PCM2_4_PATH_MUX_STAGED	0x2892
#define ES325_PCM2_5_PATH_MUX		0x2093
#define ES325_PCM2_5_PATH_MUX_STAGED	0x2893
#define ES325_PCM2_6_PATH_MUX		0x2094
#define ES325_PCM2_6_PATH_MUX_STAGED	0x2894
#define ES325_PCM2_7_PATH_MUX		0x2095
#define ES325_PCM2_7_PATH_MUX_STAGED	0x2895
#define ES325_PCM2_8_PATH_MUX		0x2096
#define ES325_PCM2_8_PATH_MUX_STAGED	0x2896
#define ES325_PCM2_9_PATH_MUX		0x2097
#define ES325_PCM2_9_PATH_MUX_STAGED	0x2897
#define ES325_PCM2_10_PATH_MUX		0x2098
#define ES325_PCM2_10_PATH_MUX_STAGED	0x2898
#define ES325_PCM2_11_PATH_MUX		0x2099
#define ES325_PCM2_11_PATH_MUX_STAGED	0x2899
#define ES325_PCM2_12_PATH_MUX		0x209A
#define ES325_PCM2_12_PATH_MUX_STAGED	0x289A
#define ES325_PCM2_13_PATH_MUX		0x209B
#define ES325_PCM2_13_PATH_MUX_STAGED	0x289B
#define ES325_PCM2_14_PATH_MUX		0x209C
#define ES325_PCM2_14_PATH_MUX_STAGED	0x289C
#define ES325_PCM2_15_PATH_MUX		0x209D
#define ES325_PCM2_15_PATH_MUX_STAGED	0x289D
#define ES325_PCM2_16_PATH_MUX		0x209E
#define ES325_PCM2_16_PATH_MUX_STAGED	0x289E
#define ES325_PCM2_17_PATH_MUX		0x209F
#define ES325_PCM2_17_PATH_MUX_STAGED	0x289F
#define ES325_PCM2_18_PATH_MUX		0x20A0
#define ES325_PCM2_18_PATH_MUX_STAGED	0x28A0
#define ES325_PCM2_19_PATH_MUX		0x20A1
#define ES325_PCM2_19_PATH_MUX_STAGED	0x28A1
#define ES325_PCM2_20_PATH_MUX		0x20A2
#define ES325_PCM2_20_PATH_MUX_STAGED	0x28A2
#define ES325_PCM2_21_PATH_MUX		0x20A3
#define ES325_PCM2_21_PATH_MUX_STAGED	0x28A3
#define ES325_PCM2_22_PATH_MUX		0x20A4
#define ES325_PCM2_22_PATH_MUX_STAGED	0x28A4
#define ES325_PCM2_23_PATH_MUX		0x20A5
#define ES325_PCM2_23_PATH_MUX_STAGED	0x28A5
#define ES325_PCM2_24_PATH_MUX		0x20A6
#define ES325_PCM2_24_PATH_MUX_STAGED	0x28A6
#define ES325_PCM2_25_PATH_MUX		0x20A7
#define ES325_PCM2_25_PATH_MUX_STAGED	0x28A7
#define ES325_PCM2_26_PATH_MUX		0x20A8
#define ES325_PCM2_26_PATH_MUX_STAGED	0x28A8
#define ES325_PCM2_27_PATH_MUX		0x20A9
#define ES325_PCM2_27_PATH_MUX_STAGED	0x28A9
#define ES325_PCM2_28_PATH_MUX		0x20AA
#define ES325_PCM2_28_PATH_MUX_STAGED	0x28AA
#define ES325_PCM2_29_PATH_MUX		0x20AB
#define ES325_PCM2_29_PATH_MUX_STAGED	0x28AB
#define ES325_PCM2_30_PATH_MUX		0x20AC
#define ES325_PCM2_30_PATH_MUX_STAGED	0x28AC
#define ES325_PCM2_31_PATH_MUX		0x20AD
#define ES325_PCM2_31_PATH_MUX_STAGED	0x28AD
#define ES325_PCM3_0_PATH_MUX		0x20AE
#define ES325_PCM3_0_PATH_MUX_STAGED	0x28AE
#define ES325_PCM3_1_PATH_MUX		0x20AF
#define ES325_PCM3_1_PATH_MUX_STAGED	0x28AF
#define ES325_PCM3_2_PATH_MUX		0x20B0
#define ES325_PCM3_2_PATH_MUX_STAGED	0x28B0
#define ES325_PCM3_3_PATH_MUX		0x20B1
#define ES325_PCM3_3_PATH_MUX_STAGED	0x28B1
#define ES325_PCM3_4_PATH_MUX		0x20B2
#define ES325_PCM3_4_PATH_MUX_STAGED	0x28B2
#define ES325_PCM3_5_PATH_MUX		0x20B3
#define ES325_PCM3_5_PATH_MUX_STAGED	0x28B3
#define ES325_PCM3_6_PATH_MUX		0x20B4
#define ES325_PCM3_6_PATH_MUX_STAGED	0x28B4
#define ES325_PCM3_7_PATH_MUX		0x20B5
#define ES325_PCM3_7_PATH_MUX_STAGED	0x28B5
#define ES325_PCM3_8_PATH_MUX		0x20B6
#define ES325_PCM3_8_PATH_MUX_STAGED	0x28B6
#define ES325_PCM3_9_PATH_MUX		0x20B7
#define ES325_PCM3_9_PATH_MUX_STAGED	0x28B7
#define ES325_PCM3_10_PATH_MUX		0x20B8
#define ES325_PCM3_10_PATH_MUX_STAGED	0x28B8
#define ES325_PCM3_11_PATH_MUX		0x20B9
#define ES325_PCM3_11_PATH_MUX_STAGED	0x28B9
#define ES325_PCM3_12_PATH_MUX		0x20BA
#define ES325_PCM3_12_PATH_MUX_STAGED	0x28BA
#define ES325_PCM3_13_PATH_MUX		0x20BB
#define ES325_PCM3_13_PATH_MUX_STAGED	0x28BB
#define ES325_PCM3_14_PATH_MUX		0x20BC
#define ES325_PCM3_14_PATH_MUX_STAGED	0x28BC
#define ES325_PCM3_15_PATH_MUX		0x20BD
#define ES325_PCM3_15_PATH_MUX_STAGED	0x28BD
#define ES325_PCM3_16_PATH_MUX		0x20BE
#define ES325_PCM3_16_PATH_MUX_STAGED	0x28BE
#define ES325_PCM3_17_PATH_MUX		0x20BF
#define ES325_PCM3_17_PATH_MUX_STAGED	0x28BF
#define ES325_PCM3_18_PATH_MUX		0x20C0
#define ES325_PCM3_18_PATH_MUX_STAGED	0x28C0
#define ES325_PCM3_19_PATH_MUX		0x20C1
#define ES325_PCM3_19_PATH_MUX_STAGED	0x28C1
#define ES325_PCM3_20_PATH_MUX		0x20C2
#define ES325_PCM3_20_PATH_MUX_STAGED	0x28C2
#define ES325_PCM3_21_PATH_MUX		0x20C3
#define ES325_PCM3_21_PATH_MUX_STAGED	0x28C3
#define ES325_PCM3_22_PATH_MUX		0x20C4
#define ES325_PCM3_22_PATH_MUX_STAGED	0x28C4
#define ES325_PCM3_23_PATH_MUX		0x20C5
#define ES325_PCM3_23_PATH_MUX_STAGED	0x28C5
#define ES325_PCM3_24_PATH_MUX		0x20C6
#define ES325_PCM3_24_PATH_MUX_STAGED	0x28C6
#define ES325_PCM3_25_PATH_MUX		0x20C7
#define ES325_PCM3_25_PATH_MUX_STAGED	0x28C7
#define ES325_PCM3_26_PATH_MUX		0x20C8
#define ES325_PCM3_26_PATH_MUX_STAGED	0x28C8
#define ES325_PCM3_27_PATH_MUX		0x20C9
#define ES325_PCM3_27_PATH_MUX_STAGED	0x28C9
#define ES325_PCM3_28_PATH_MUX		0x20CA
#define ES325_PCM3_28_PATH_MUX_STAGED	0x28CA
#define ES325_PCM3_29_PATH_MUX		0x20CB
#define ES325_PCM3_29_PATH_MUX_STAGED	0x28CB
#define ES325_PCM3_30_PATH_MUX		0x20CC
#define ES325_PCM3_30_PATH_MUX_STAGED	0x28CC
#define ES325_PCM3_31_PATH_MUX		0x20CD
#define ES325_PCM3_31_PATH_MUX_STAGED	0x28CD
#define ES325_SBUS_TX0_PATH_MUX		0x20CE
#define ES325_SBUS_TX0_PATH_MUX_STAGED	0x28CE
#define ES325_SBUS_TX1_PATH_MUX		0x20CF
#define ES325_SBUS_TX1_PATH_MUX_STAGED	0x28CF
#define ES325_SBUS_TX2_PATH_MUX		0x20D0
#define ES325_SBUS_TX2_PATH_MUX_STAGED	0x28D0
#define ES325_SBUS_TX3_PATH_MUX		0x20D1
#define ES325_SBUS_TX3_PATH_MUX_STAGED	0x28D1
#define ES325_SBUS_TX4_PATH_MUX		0x20D2
#define ES325_SBUS_TX4_PATH_MUX_STAGED	0x28D2
#define ES325_SBUS_TX5_PATH_MUX		0x20D3
#define ES325_SBUS_TX5_PATH_MUX_STAGED	0x28D3
#define ES325_FLUSH		0x20D4
#define ES325_FLUSH_STAGED	0x28D4

#endif /* _ES325_H */
