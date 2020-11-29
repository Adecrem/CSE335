/**
 * \file Timeline.h
 *
 * \author Andrew Decrem
 *
 * Timeline class
 */
#pragma once
#include <vector>
#include "Drawable.h"
class CAnimChannel;
class CTimeline
{
public:
    ///Constructor
    CTimeline();
    ///Destructor
    virtual ~CTimeline();
    ///Disable the copy constructor
    CTimeline(const CTimeline&) = delete;
    ///Disable the assignment constructor
    void operator=(const CTimeline&) = delete;
    /** Get the number of frames in the animation
 * \returns Number of frames in the animation
 */
    int GetNumFrames() const { return mNumFrames; }

    /** Set the number of frames in the animation
     * \param numFrames Number of frames in the animation
     */
    void SetNumFrames(int numFrames) { mNumFrames = numFrames; }

    /** Get the frame rate
     * \returns Animation frame rate in frames per second
     */
    int GetFrameRate() const { return mFrameRate; }

    /** Set the frame rate
     * \param frameRate Animation frame rate in frames per second
     */
    void SetFrameRate(int frameRate) { mFrameRate = frameRate; }

    /** Get the current time
     * \returns Current animation time in seconds
     */
    double GetCurrentTime() const { return mCurrentTime; }

    /** Set the current time
     * \param currentTime new current animation time in seconds
     */
    //void SetCurrentTime(double currentTime) { mCurrentTime = currentTime; }
    void SetCurrentTime(double t);
    /** Get the current frame.
 *
 * This is the frame associated with the current time
 * \returns Current frame
 */
    int GetCurrentFrame() const { return int(mCurrentTime) * mFrameRate; }

    /** Get the animation duration
     * \returns Animation duration in seconds
     */
    double GetDuration() const { return double(mNumFrames) / mFrameRate; }

    void AddChannel(CAnimChannel* channel);

    void DeleteKeyframe();
    
private:
    int mNumFrames = 300; ///< Given number of frames
    int mFrameRate = 30; ///< frame rate
    double mCurrentTime = 0; ///< set time
    std::vector<CAnimChannel*> mChannels; ///< Define channel
};

