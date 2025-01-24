/*
 * Deskflow -- mouse and keyboard sharing utility
 * Copyright (C) 2025 Deskflow Developers
 * Copyright (C) 2021 Barrier contributors
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "FingerprintAcceptDialog.h"
#include "net/SecureUtils.h"
#include "ui_FingerprintAcceptDialog.h"

FingerprintAcceptDialog::FingerprintAcceptDialog(
    QWidget *parent, AppRole type, const deskflow::FingerprintData &fingerprint_sha1,
    const deskflow::FingerprintData &fingerprint_sha256
)
    : QDialog(parent),
      ui{std::make_unique<Ui::FingerprintAcceptDialog>()}
{
  ui->setupUi(this);

  if (type == AppRole::Server) {
    ui->label_sha1->hide();
    ui->label_sha1_fingerprint_full->hide();
  } else {
    ui->label_sha1_fingerprint_full->setText(
        QString::fromStdString(deskflow::format_ssl_fingerprint(fingerprint_sha1.data))
    );
  }

  ui->label_sha256_fingerprint_full->setText(
      QString::fromStdString(deskflow::format_ssl_fingerprint_columns(fingerprint_sha256.data))
  );
  ui->label_sha256_fingerprint_randomart->setText(
      QString::fromStdString(deskflow::create_fingerprint_randomart(fingerprint_sha256.data))
  );

  QString explanation;
  if (type == AppRole::Server) {
    explanation = tr("This is a client fingerprint. You should compare this "
                     "fingerprint to the one on your client's screen. If the "
                     "two don't match exactly, then it's probably not the client "
                     "you're expecting (it could be a malicious user).\n\n"
                     "To automatically trust this fingerprint for future "
                     "connections, click Yes. To reject this fingerprint and "
                     "disconnect the client, click No.");
  } else {
    explanation = tr("This is a server fingerprint. You should compare this "
                     "fingerprint to the one on your server's screen. If the "
                     "two don't match exactly, then it's probably not the server "
                     "you're expecting (it could be a malicious user).\n\n"
                     "To automatically trust this fingerprint for future "
                     "connections, click Yes. To reject this fingerprint and "
                     "disconnect from the server, click No.");
  }
  ui->label_explanation->setText(explanation);
}

FingerprintAcceptDialog::~FingerprintAcceptDialog() = default;
