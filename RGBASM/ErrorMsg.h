#ifndef __ERRORMSG_H__
#define __ERRORMSG_H__

class ErrorMsg
	{
	public:
		ErrorMsg(void) ;
		void Error(int errMsgNum) ;
		void Warning(int errMsgNum) ;
		void Fatal(int errMsgNum) ;

		int TotalErrors(void) { return (m_errorCount) ; }
		int TotalWarnings(void) { return (m_warningCount) ; }

	private:
		int	m_errorCount ;
		int m_warningCount ;

	} ;

#endif	// __ERRORMSG_H__
