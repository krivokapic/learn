#include <stdio.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int numOfCols, char **rowData, char **rowColName) {
	for (int i = 0; i < numOfCols; i++) {
		printf("%s = %s\n", rowColName[i], rowData[i] ? rowData[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main() {
	sqlite3 *db;
	char *err_msg = 0;
	int rc;

	rc = sqlite3_open("sales.db", &db);
	if (rc) {
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		return(1);
	}

	const char *sql = "SELECT * FROM sales limit 5;";
	rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
	if (rc != SQLITE_OK ) {
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	}

	sqlite3_close(db);

}
