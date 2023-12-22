

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
/* TCCR0 */
#define  foc0 7
#define  wgm00  6
#define  com01 5
#define  com00 4
#define  wgm01  3
#define  cs02 2
#define  cs01 1
#define  cs00 0
/* TIMSK*/
#define  ocie2 7
#define  toie2 6
#define  ticie1 5
#define  ocie1a 4
#define  ocie1b 3
#define  toie1 2
#define ocie0 1
#define  toie0 0
/*flags*/
#define tov0 0
#define  ocf0 1
/*timer modes*/
#define normal 0
#define pwm_phase_correct  1
#define  ctc 2
#define fast_pwm 3
/*timer mode choice */
#define  timer_mode  normal
/* prescales */
#define no_clock_source  0
#define no_prescaler 1
#define  prescaler_8  2
#define  prescaler_64  3
#define  prescaler_256  4
#define  prescaler_1024  5
#define  exit_falling_edge 6
#define  exit_rising_edge 7
/*time 0 prescaler choice */
#define  time0_prescaler   prescaler_64
/* timer oc0 mode */
#define oc0_disconnected  0
#define toggle_oc0    1
#define clear_oc0 2
#define  set_oc0  3
#define  reserved 4

#define  timer_oc0_mode oc0_disconnected




 
#endif /* TIMER_CONFIG_H_ */