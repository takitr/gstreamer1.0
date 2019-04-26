/*
 * SegmentTemplateStream.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_MPD_SEGMENTTEMPLATESTREAM_H_
#define LIBDASH_FRAMEWORK_MPD_SEGMENTTEMPLATESTREAM_H_

#include <math.h>

#include "IMPD.h"
#include "AbstractRepresentationStream.h"
#include "ISegment.h"
#include "ISegmentTemplate.h"

namespace libdash
{
    namespace framework
    {
        namespace mpd
        {
            class SegmentTemplateStream: public AbstractRepresentationStream
            {
                public:
                    SegmentTemplateStream           (dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);
                    virtual ~SegmentTemplateStream  ();

                    virtual dash::mpd::ISegment*        GetInitializationSegment        ();
                    virtual dash::mpd::ISegment*        GetIndexSegment                 (size_t segmentNumber);
                    virtual dash::mpd::ISegment*        GetMediaSegment                 (size_t segmentNumber);
                    virtual dash::mpd::ISegment*        GetBitstreamSwitchingSegment    ();
                    virtual RepresentationStreamType    GetStreamType                   ();
                    virtual uint32_t                    GetSize                         ();

                    virtual uint32_t                    GetAverageSegmentDuration       ();
                    virtual uint32_t                    GetSegmentTimescale       ();

                    virtual uint64_t                    GetSegmentStartTimeByOffset(uint32_t offset);
                    virtual int32_t                     GetSegmentOffsetByTime(uint64_t timeToFind);
                    virtual uint32_t                   GetStartNumber();
                    virtual bool                         HasTimeLineOrNot();

                private:
                    dash::mpd::ISegmentTemplate*        FindSegmentTemplate             ();
                    void                                CalculateSegmentStartTimes      ();

                    dash::mpd::ISegmentTemplate *segmentTemplate;
                    std::vector<uint64_t>       segmentStartTimes;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_MPD_SEGMENTTEMPLATESTREAM_H_ */
