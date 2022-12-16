#pragma once

#include "c_ressource.h"

namespace libav {
   using Codec = stdex::c_resource<AVCodecContext, avcodec_alloc_context3, avcodec_free_context>;
   using File = stdex::c_resource<AVFormatContext, avformat_open_input, avformat_close_input>;
   using tFrame  = stdex::c_resource<AVFrame, av_frame_alloc, av_frame_free>;
   using tPacket = stdex::c_resource<AVPacket, av_packet_alloc, av_packet_free>;

// frames and packets are reference-counted and always constructed non-empty
struct Frame : tFrame 
{
	[[nodiscard]] Frame() : tFrame(constructed){};
	[[nodiscard]] auto dropReference() { return Frame::guard<av_frame_unref>(*this); }
};

struct Packet : tPacket 
{
	[[nodiscard]] Packet() : tPacket(constructed){};
	[[nodiscard]] auto dropReference() { return Packet::guard<av_packet_unref>(*this); }
};

} // namespace libav
