/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ACSDK_ALEXAREMOTEVIDEOPLAYERINTERFACES_REMOTEVIDEOPLAYERTYPES_H_
#define ACSDK_ALEXAREMOTEVIDEOPLAYERINTERFACES_REMOTEVIDEOPLAYERTYPES_H_

#include <chrono>
#include <string>
#include <vector>

#include <AVSCommon/Utils/Optional.h>

#include <acsdk/VideoContent/VideoEntityTypes.h>

namespace alexaClientSDK {
namespace alexaRemoteVideoPlayerInterfaces {

/**
 * Context of the request provided with Alexa.RemoteVideoPlayer directives. To fetch all the entity objects from the
 * context, application can query the the getters to fetch the list of entities based on the types provided with
 * requestedEntityType.
 */
struct RemoteVideoPlayerRequest {
    /**
     * A time window type.
     */
    struct TimeWindow {
        /**
         * Default constructor.
         */
        TimeWindow() {
        }
        /// The start time for the time window.
        avsCommon::utils::Optional<std::chrono::time_point<std::chrono::system_clock>> startTime;
        /// The end time for the time window.
        avsCommon::utils::Optional<std::chrono::time_point<std::chrono::system_clock>> endTime;
    };
    /// Collection of all the media objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Media> mediaList;

    /// Collection of all the actor objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Actor> actorList;

    /// Collection of all the app objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::App> appList;

    /// Collection of all the channel objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Channel> channelList;

    /// Collection of all the character objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Character> characterList;

    /// Collection of all the director objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Director> directorList;

    /// Collection of all the episode objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Episode> episodeList;

    /// Collection of all the event objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Event> eventList;

    /// Collection of all the franchise objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Franchise> franchiseList;

    /// Collection of all the genre objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Genre> genreList;

    /// Collection of all the league objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::League> leagueList;

    /// Collection of all the popularity objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Popularity> popularityList;

    /// Collection of all the production company objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::ProductionCompany> productionCompanyList;

    /// Collection of all the recency objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Recency> recencyList;

    /// Collection of all the seasons objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Season> seasonList;

    /// Collection of all the sport objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Sport> sportList;

    /// Collection of all the sports team objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::SportsTeam> sportsTeamList;

    /// Collection of all the video objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::Video> videoList;

    /// Collection of all the video resolution objects.
    std::vector<acsdkAlexaVideoCommon::VideoEntity::VideoResolution> videoResolutionList;

    /// The transcribed version of the user search query.
    /// @Note: This is to be used as a fallback for other values in the search payload. This field is
    /// optional, and might not appear in the received directive.
    /// Additionally (1). there is no word order guarantee in the transcribed text,
    /// and, (2). the content of the transcribed text may change over time - e.g. "top ten comedies" or "top 10
    /// comedies".
    avsCommon::utils::Optional<std::string> searchTextTranscribed;

    /// A time window object representing a time associated with this request.
    avsCommon::utils::Optional<TimeWindow> timeWindow;
};
}  // namespace alexaRemoteVideoPlayerInterfaces
}  // namespace alexaClientSDK

#endif  // ACSDK_ALEXAREMOTEVIDEOPLAYERINTERFACES_REMOTEVIDEOPLAYERTYPES_H_