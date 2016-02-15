/*
 * Copyright 2014-2016 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000, there is a non-exclusive license for use of this work
 * by or on behalf of the U.S. Government. Export of this program may require
 * a license from the United States Government.
 *
 * This file is part of the Power API Prototype software package. For license
 * information, see the LICENSE file in the top level directory of the
 * distribution.
*/

#include "pwr.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

int section_4_1_test( void )
{
    int rc;
    PWR_Cntxt 
        role_app, 
        role_mc, 
        role_os, 
        role_user, 
        role_rm, 
        role_admin, 
        role_mgr, 
        role_acc,
        role_inv,
        role_ns;

    printf( "\tPWR_CntxtInit - application context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_APP, "Application", &role_app );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI application context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - monitor and control context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_MC, "MonitorControl", &role_mc );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI monitor and control context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - operating system context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_OS, "OperatingSystem", &role_os );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI operating system context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - user context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_USER, "", &role_user );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI user context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - resource manager context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_RM, "ResourceManager", &role_rm );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI resource manager context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - administrator context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_ADMIN, "Administrator", &role_admin );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI administrator context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - HPCS manager context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_MGR, "HPCSManager", &role_mgr );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI HPCS manager context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - accounting context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_ACC, "Accounting", &role_acc );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI accounting context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - invalid context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_INVALID, "Invalid", &role_inv );
    if( rc == PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI invalid context succeeded\n" );
        return -1;
    }

    printf( "\tPWR_CntxtInit - not specified context\n" );
	rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_NOT_SPECIFIED, "NotSpecified", &role_ns );
    if( rc == PWR_RET_SUCCESS ) {
        printf( "\t\tError: initialization of PowerAPI not specified context succeeded\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - application context\n" );
    rc = PWR_CntxtDestroy( role_app );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI application context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - monitor and control context\n" );
    rc = PWR_CntxtDestroy( role_mc );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI monitor and control context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - operating system context\n" );
    rc = PWR_CntxtDestroy( role_os );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI operating system context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - user context\n" );
    rc = PWR_CntxtDestroy( role_user );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI user context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - resource manager context\n" );
    rc = PWR_CntxtDestroy( role_rm );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI resource manager context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - administrator context\n" );
    rc = PWR_CntxtDestroy( role_admin );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI administrator context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - HPCS manager context\n" );
    rc = PWR_CntxtDestroy( role_mgr );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI HPCS manager context failed\n" );
        return -1;
    }

    printf( "\tPWR_CntxtDestroy - accounting context\n" );
    rc = PWR_CntxtDestroy( role_acc );
    if( rc != PWR_RET_SUCCESS ) {
        printf( "\t\tError: destruction of PowerAPI accounting context failed\n" );
        return -1;
    }

    return 0;
}