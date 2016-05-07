/*
 * Copyright © 2016 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
*/

#ifndef KandyConnectServiceEnums_h
#define KandyConnectServiceEnums_h
static NSString * const KandyConnectServiceErrorDomain = @"connectServiceErrorDomain";

/**
 *  Enum describing the registration state
 */
typedef NS_ENUM(NSUInteger, EKandyRegistrationState){
    /**
     *  unregistering from the service
     */
    EKandyRegistrationState_unregistering,
    /**
     *  not registered
     */
    EKandyRegistrationState_unregistered,
    /**
     *  registering to the service
     */
    EKandyRegistrationState_registering,
    /**
     *  registered in the system
     */
    EKandyRegistrationState_registered,
};

/**
 *  Enum describing the registration state
 */
typedef NS_ENUM(NSUInteger, EKandyConnectionState){
    /**
     *  disconnecting from the server
     */
    EKandyConnectionState_disconnecting,
    /**
     *  not connected
     */
    EKandyConnectionState_disconnected,
    /**
     *  connecting to the server
     */
    EKandyConnectionState_connecting,
    /**
     *  connected to the server
     */
    EKandyConnectionState_connected,
};

/**
 *  Connect service enums
 */
typedef NS_ENUM(NSUInteger, EKandyConnectServiceError){
    /**
     *  no available server
     */
    EKandyConnectServiceError_noAvailableServer = 1000,
    /**
     *  wrong credentials
     */
    EKandyConnectServiceError_authenticationFailed,
    /**
     *  The connection dropped
     */
    EKandyConnectServiceError_connectionDropped,
    /**
     *  Did not succeed to start the initial connection with the server
     */
    EKandyConnectServiceError_serverInitialConnectionFailed,
    /**
     *  user is already not registered
     */
    EKandyConnectServiceError_userNotRegistered,
    /**
     *  missing config to connect the server - usually IP + host
     */
     EKandyConnectServiceError_serverConfigurationMissing,
    /**
     *  operation failed
     */
    EKandyConnectServiceError_logoutFailed,
    /**
     *  the remote server is busy
     */
    EKandyConnectServiceError_remoteServerBusy,
    /**
     *  development use
     */
    EKandyConnectServiceError_count
};

/**
 *  Enum defining the socket type
 */
typedef NS_ENUM(NSUInteger, EKandySocketType){
    /**
     *  socket of type TCP
     */
    EKandySocketType_tcpSocket,
    /**
     *  web socket
     */
    EKandySocketType_webSocket,
};

#endif //KandyConnectServiceEnums_h
