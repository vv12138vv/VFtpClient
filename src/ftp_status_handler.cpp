//
// Created by jgss9 on 10/25/2023.
//

#include "ftp_status_handler.h"

FtpStatusHandler &FtpStatusHandler::getInstance() {
    static FtpStatusHandler instance_;
    return instance_;
}

FtpStatusHandler::FtpStatusHandler() {

}

void handle220(){

}