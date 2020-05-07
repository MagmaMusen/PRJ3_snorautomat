#ifndef EXIT_HPP
#define	EXIT_HPP

#include <osapi/Message.hpp>
#include <osapi/MsgQueue.hpp>
#include <osapi/ThreadFunctor.hpp>
#include "EntryGuard.hpp"

class ExitGuard : public osapi::ThreadFunctor
{
	public:
		enum
		{
			ID_START_IND,
            ID_ENTRYBARRIER_OPEN_CFM,
            ID_ENTRYBARRIER_OPEN_REQ,
            ID_EXITBARRIER_OPEN_CFM,
            ID_EXITBARRIER_OPEN_REQ
		};
		static const int MAX_QUEUE_SIZE = 10;
		ExitGuard();
		osapi::MsgQueue* getMsgQueue();

	private:
		bool running_;
		osapi::MsgQueue mq_;
		void exitBarrierControllerHandler(unsigned long id, osapi::Message* msg);
		void exitBarrierControllerHandlerIdExitBarrierOpenReq(BarrierOpenReq* req);

	protected:
		virtual void run();
	};



#endif
