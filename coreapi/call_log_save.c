#include <stdio.h>
#include <stdlib.h>

static FILE * fLog;
int write_log_header(){
	char * tmp_path = getenv("HOME");
	char path[100];
	sprintf(path, "%s/.linphone/lp_recentcalls.xml", tmp_path);
	fLog = fopen(path, "w");
	if(fLog == NULL) return -1;

	fprintf(fLog, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<?mso-application progid=\"Excel.Sheet\"?><Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:c=\"urn:schemas-microsoft-com:office:component:spreadsheet\" xmlns:html=\"http://www.w3.org/TR/REC-html40\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:x2=\"http://schemas.microsoft.com/office/excel/2003/xml\" xmlns:x=\"urn:schemas-microsoft-com:office:excel\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"><OfficeDocumentSettings xmlns=\"urn:schemas-microsoft-com:office:office\"><Colors><Color><Index>3</Index><RGB>#c0c0c0</RGB></Color><Color><Index>4</Index><RGB>#ff0000</RGB></Color></Colors></OfficeDocumentSettings><ExcelWorkbook xmlns=\"urn:schemas-microsoft-com:office:excel\"><WindowHeight>9000</WindowHeight><WindowWidth>13860</WindowWidth><WindowTopX>240</WindowTopX><WindowTopY>75</WindowTopY><ProtectStructure>False</ProtectStructure><ProtectWindows>False</ProtectWindows></ExcelWorkbook><Styles><Style ss:ID=\"Default\" ss:Name=\"Default\"/><Style ss:ID=\"Result\" ss:Name=\"Result\"><Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Size=\"10\" ss:Underline=\"Single\"/></Style><Style ss:ID=\"Result2\" ss:Name=\"Result2\"><Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Size=\"10\" ss:Underline=\"Single\"/><NumberFormat ss:Format=\"Currency\"/></Style><Style ss:ID=\"Heading\" ss:Name=\"Heading\"><Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Size=\"16\"/></Style><Style ss:ID=\"Heading1\" ss:Name=\"Heading1\"><Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Size=\"16\"/></Style><Style ss:ID=\"co1\"/><Style ss:ID=\"co2\"/><Style ss:ID=\"co3\"/><Style ss:ID=\"co4\"/><Style ss:ID=\"co5\"/><Style ss:ID=\"co6\"/><Style ss:ID=\"co7\"/><Style ss:ID=\"ta1\"/></Styles><ss:Worksheet ss:Name=\"Sheet1\"><Table ss:StyleID=\"ta1\"><Column ss:Width=\"44.8416\"/><Column ss:Width=\"35.0352\"/><Column ss:Width=\"70.9488\"/><Column ss:Width=\"181.1592\"/><Column ss:Span=\"1\" ss:Width=\"181.4472\"/><Column ss:Span=\"2\" ss:Index=\"7\" ss:Width=\"64.008\"/><Row ss:AutoFitHeight=\"0\" ss:Height=\"12.8376\"><Cell><Data ss:Type=\"String\">No.</Data></Cell><Cell><Data ss:Type=\"String\">Dir</Data></Cell><Cell><Data ss:Type=\"String\">Status</Data></Cell><Cell><Data ss:Type=\"String\">From</Data></Cell><Cell><Data ss:Type=\"String\">To</Data></Cell><Cell><Data ss:Type=\"String\">Time</Data></Cell><Cell><Data ss:Type=\"String\">Duration</Data></Cell><Cell><Data ss:Type=\"String\">Quality</Data></Cell><Cell><Data ss:Type=\"String\">Video enable</Data></Cell><Cell><Data ss:Type=\"String\">Call ID</Data></Cell></Row>\n");
	return 0;
}

int write_log_footer(){
	fprintf(fLog, "</Table><x:WorksheetOptions/></ss:Worksheet></Workbook>\n");
	fclose(fLog);
	return 0;
}

int write_log_row(int num, int dir, char * status, char * from, char * to, char * time, int duration, float quality, int video, char * id){
	fprintf(fLog, "<Row ss:AutoFitHeight=\"0\" ss:Height=\"12.8376\"><Cell><Data ss:Type=\"Number\">%d</Data></Cell><Cell><Data ss:Type=\"Number\">%d</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell><Cell><Data ss:Type=\"Number\">%d</Data></Cell><Cell><Data ss:Type=\"Number\">%f</Data></Cell><Cell><Data ss:Type=\"Number\">%d</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell></Row>\n", num, dir, status, from, to, time, duration, quality, video, id);
	return 0;
}