/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "FirebaseAuth/Sources/Backend/FIRAuthRPCRequest.h"

@protocol FIRHeartbeatLoggerProtocol;

NS_ASSUME_NONNULL_BEGIN

/** @class FIRAuthRequestConfiguration
    @brief Defines configurations to be added to a request to Firebase Auth's backend.
  */
@interface FIRAuthRequestConfiguration : NSObject

/** @property APIKey
    @brief The Firebase Auth API key used in the request.
 */
@property(nonatomic, copy, readonly) NSString *APIKey;

/** @property appID
    @brief The Firebase appID used in the request.
 */
@property(nonatomic, copy, readonly) NSString *appID;

/** @property heartbeatLogger
    @brief The heartbeat logger used to add heartbeats to the corresponding request's header.
 */
@property(nonatomic, copy, nullable) id<FIRHeartbeatLoggerProtocol> heartbeatLogger;

/** @property LanguageCode
    @brief The language code used in the request.
 */
@property(nonatomic, copy, nullable) NSString *languageCode;

/** @property additionalFrameworkMarker
    @brief Additional framework marker that will be added as part of the header of every request.
 */
@property(nonatomic, copy, nullable) NSString *additionalFrameworkMarker;

/** @property emulatorHostAndPort
    @brief If set, the local emulator host and port to point to instead of the remote backend.
 */
@property(nonatomic, copy, nullable) NSString *emulatorHostAndPort;

- (instancetype)init NS_UNAVAILABLE;

/** @fn initWithAPIKey:appID:
    @brief Convenience initializer.
    @param APIKey The API key to be used in the request.
    @param appID The Firebase app ID to be passed in the request header.
 */
- (nullable instancetype)initWithAPIKey:(NSString *)APIKey appID:(NSString *)appID;

/** @fn initWithAPIKey:appID:heartbeatLogger:
    @brief Designated initializer.
    @param APIKey The API key to be used in the request.
    @param appID The Firebase app ID to be passed in the request header.
    @param heartbeatLogger The heartbeat logger used to add heartbeats to the request header.
 */
- (nullable instancetype)initWithAPIKey:(NSString *)APIKey
                                  appID:(NSString *)appID
                        heartbeatLogger:(nullable id<FIRHeartbeatLoggerProtocol>)heartbeatLogger
    NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
